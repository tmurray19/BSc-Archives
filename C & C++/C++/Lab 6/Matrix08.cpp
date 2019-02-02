/*Taidgh Murray
ID: 15315901
*/

#include <iostream>
#include "Vector08.h"
#include "Matrix08.h"

using namespace std;

// Basic constructor. See below for copy constructor.
matrix::matrix (unsigned int Size){
  N = Size;
  entries = new double [N*N];
}

matrix::~matrix(void){
  delete [] entries;
}

void matrix::setij (unsigned int i, unsigned int j, double x){
  if (i<N && j<N)
    entries[i*N+j]=x;
  else
    cerr << "matrix::setij(): Index out of bounds." << endl;
}

double matrix::getij (unsigned int i, unsigned int j){
  if (i<N && j<N)
    return(entries[i*N+j]);
  else
  {
    cerr << "matrix::getij(): Index out of bounds." << endl;
    return(0);
  }
}

void matrix::print (void){
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      cout << "[" << entries[i*N+j] << "]";
    cout << endl;
  }
}

// Matrix copy constructor
matrix::matrix (const matrix &m){
  N = m.N;
  entries = new double[N*N];
  for (unsigned int i=0; i<N*N; i++)
    entries[i] = m.entries[i];
}


// Overload the assignment = operator.
matrix &matrix::operator=(const matrix &B){
  if (this == &B)
    return(*this); // Taking care for self-assignment

  delete [] entries; // Just in case there was any memory
  // already allocated to this

  entries = new double[(B.N)*(B.N)];
  for (unsigned int i=0; i<N*N; i++)
    entries[i] = B.entries[i];

  return(*this);
}

// Overload the operator multiplication (*) for a matrix-vector
// product. Matrix is passed implicitly as "this", the vector is
// passed explicitly. Will return v=(this)*u
vector matrix::operator*(vector u){
  vector v(N); // v = A*w, where A is the implicitly passed matrix
  if (N != u.size())
    cerr << "Error: matrix::operator* - dimension mismatch" << endl;
  else
    for (unsigned int i=0; i<N; i++){
      double x=0;
      for (unsigned int j=0; j<N; j++)
	x += entries[i*N+j]*u.geti(j);
      v.seti(i,x);
    }
  return(v);
}

// Overload the operator/ (division) operator to do a back-subs
// To solve Lx=b
// This will only work if L is lower triangular
vector operator/(vector b, matrix L){
   unsigned int N = L.size();
   vector x(N); // x solves L*x=b
   if (N != x.size()){
     cerr << "Error: operator/(vector,matrix) - dimension mismatch" << endl;
      return(x);
   }

   // Now do a back-subs
   for (unsigned int i=0; i<N; i++){
      double q=b.geti(i);
      for (unsigned int j=0; j<i; j++)
	 q -= L.getij(i,j)*x.geti(j);
      q /= L.getij(i,i);
      x.seti(i,q);
   }
   return(x);
}

