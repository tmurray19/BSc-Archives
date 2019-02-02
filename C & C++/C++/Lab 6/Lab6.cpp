/*Taidgh Murray
ID: 15315901
*/

using namespace std;

#include <iostream>
#include <stdlib.h>

#include "Matrix08.h"
#include "Vector08.h"
#include "Vector08.cpp"
#include "Matrix08.cpp"


//construction of functions for Jacobi and Gauss-Seidel functions
void Jacobi(matrix &A, vector &b, vector &v, unsigned int &count, double tol=1e-6);
void GaussSeidel(matrix &A, vector &b, vector &v, unsigned int &count, double tol=1e-6);


//initialisng user inputed values for tolerance and iterations
double tolerance = 0;
unsigned int max_iterations = 0;


int main(void){
   //NxN sized matrix
   unsigned int N=6;
   unsigned int iterations;

   matrix A(N);
   vector x(N), b(N); // A*x=b

   /* Initialise the entries of A.
   We choose the off-diagonal entries to be random numbers between -3 and 3.
   The  diagonal entries,will be the sum of the absolute value of the others +1.
   We make the random entries in [-3,3] by picking a random number between 0 and 6, and then subtracting 3.
   The entries in the solution vector, x,  are all 1. Then we choose the solution right-hand side so A*x=b */
   for (unsigned int i=0; i<N; i++){
      A.setij(i,i, 0.0);
      for (unsigned int j=0; j<N; j++)
	 if (i != j){
	    A.setij(i,j, (double) (rand()%6-3));
	    A.setij(i,i, A.getij(i,i) + abs(A.getij(i,j)));
	 }
      x.seti(i, 1.0 );
      A.setij(i,i, A.getij(i,i)+1.0);
   }

   cout << "A=" << endl;
   A.print();

   b=A*x;
   cout << "b=A*x" << endl;
   b.print();


   // We will now use the Jacobi method to approximate the solution
   // The Jacobi solution is called estimate
   vector estimate(N);
   estimate.zero();

   //allowing user to input tolerance and iterations
   cout << "Enter desired tolerance: " << endl;
   cin >> tolerance;

   cout << "Enter maximum desired number of iterations: " << endl;
   cin >> max_iterations;

   //Jacobi algorithm
   Jacobi(A, b, estimate, iterations, tolerance);
   cout << "Jacobi took " << iterations << " iterations. Estimate is : " << endl;
   estimate.print();
   cout << "The norm of the error is: ";
   vector error=x-estimate;
   cout << error.norm() << endl << endl;

   //Gauss-Seidel algorithm
   estimate.zero();
   GaussSeidel(A, b, estimate, iterations, tolerance);
   cout << "Gauss-Seidel took " << iterations << " iterations." << endl;
   cout << "The estimate is : " << endl;
   estimate.print();
   error=x-estimate;
   cout << "The error is : " << error.norm() << endl << endl;;

   // Not sure about the next bit: might need "#ifdef WIN32" or "#ifdef WIN64"
   #ifdef _WIN32
   system("PAUSE");
   #endif
   return (0);
}


// Use Jacobi's method to solve Ax=b,
// On entry : x is the initial guess
// On entry : x is the estimate for the solution
void Jacobi(matrix &A, vector &b, vector &x, unsigned int &count, double tol){
   unsigned int N= A.size();
   count =0;
   //error handler
   if ( (N != b.size()) || (N != x.size() ) )
      cerr << "Jacobi: error - A must be the same size as b,x\n" << endl;

   // Form the diagonal and off-diagonal matrices
   matrix Dinv(N), T(N);
   for (unsigned int i=0; i<N; i++)
      for (unsigned int j=0; j<N; j++)
	 if (j != i)
	 {
            T.setij(i,j, -A.getij(i,j));
            Dinv.setij(i,j,0.0);
         }
         else
         {
            T.setij(i,j, 0.0);
            Dinv.setij(i,j, 1.0/A.getij(i,j));
         }

   // Now implement the algorithm:
   vector r(N);
   do{
      count++;
      //if clause for if the max iterations value is reached
      if (count > max_iterations){
        cout << "Maximum number of iterations reached." << endl;
        exit(0);
      }
      x = Dinv*(b+T*x); // set x = inverse(D)*(b+T*x)
      r=b-A*x; // set r=b-A*r
   }   while ( r.norm() > tol);
}

// Use the GaussSeidel method to solve Ax=b,
// On entry : x is the initial guess
// On entry : x is the estimate for the solution
void GaussSeidel(matrix &A, vector &b, vector &x, unsigned int &count, double tol){
   unsigned int N= A.size();
   count =0;
   if ( (N != b.size()) || (N != x.size() ) )
      cout << "Gauss-Seidel: error - A must be the same size as b,x\n" << endl;

   // Form the diagonal and off-diagonal matrices
   matrix L(N), U(N);
   for (unsigned int i=0; i<N; i++)
      for (unsigned int j=0; j<N; j++)
	 if (i>=j){
	    L.setij(i,j, A.getij(i,j));
	    U.setij(i,j, 0);
	 }
         else{
            U.setij(i,j, -A.getij(i,j));
            L.setij(i,j, 0);
	 }
   // Now implement the algorithm:
   vector r(N);
   do{
      count++;
      //if clause for if the max iterations value is reached
      if (count > max_iterations){
        cout << "Maximum number of iterations reached." << endl;
        exit(0);
      }
      x = (U*x+b)/L; // set x = inverse(D)*(b+T*x)
      r=b-A*x; // set r=b-A*r
      }
   while ( r.norm() > tol);
}
