/*Taidgh Murray
ID: 15315901
*/

#include <iostream>
#include <math.h>
#include "Vector08.h"

using namespace std;

vector::vector (unsigned int N){
  this->N = N;
  entries = new double[N];
}

// copy constructor
vector::vector (const vector &old_vector){
  N = old_vector.N;
  entries = new double[N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = old_vector.entries[i];
}

// destructor
vector::~vector (){
  delete [] entries;
}

void vector::seti (unsigned int i, double x){
  if (i<N)
    entries[i]=x;
  else
    cerr << "vector::seti(): Index out of bounds." << endl;
}

double vector::geti (unsigned int i){
  if (i<N)
    return(entries[i]);
  else
  {
    cerr << "vector::geti(): Index out of bounds." << endl;
    return(0);
  }
}


void vector::print (void){
  for (unsigned int i=0; i<N; i++)
    cout << "[" << entries[i] << "]" << endl;
}

double vector::norm (void){
  double x=0;
  for (unsigned int i=0; i<N; i++)
    x+=entries[i]*entries[i];
  return (sqrt(x));
}

void vector::zero(void){
  for (unsigned int i=0; i<N; i++)
    entries[i]=0;
}


// Overload the = operator.
vector &vector::operator=(const vector &b){
  if (this == &b)
    return(*this); // Taking care for self-assignment

  delete [] entries; // In case memory was already allocated

  N = b.N;
  entries = new double[b.N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = b.entries[i];

  return(*this);
}

// Overload the + operator. For Lectures 10 and 11
vector vector::operator+(vector b){
  vector c(N); // Make c the size of a
  if (N != b.N)
    cerr << "vector::+ : cant add two vectors of different size!" << endl;
  else
    for (unsigned int i=0; i<N; i++)
      c.entries[i] = entries[i] + b.entries[i];

  return(c);
}

// Overload the unary minus (-) operator. As in b=-a;
vector vector::operator-(void){
  vector b(N); // Make b the size of a
  for (unsigned int i=0; i<N; i++)
    b.entries[i] = -entries[i];
  return(b);
}

// Overload the binary minus (-) operator. As in c=a-b
// This implementation reuses the unary minus (-) operator
vector vector::operator-(vector b){
  vector c(N); // Make b the size of a
  if (N != b.N)
    cerr << "vector:: operator- : dimension mismatch!" << endl;
  else
    c = *this + (-b);
  return(c);
}
