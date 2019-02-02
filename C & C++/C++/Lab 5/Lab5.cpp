#include <iostream>
#include <stdlib.h>

#include "Vector.cpp"
#include "Matrix.cpp"

using namespace std;

//  c=alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (vector &c, vector &a, vector &b, double alpha=1.0, double beta=1.0);

//  Compute a matrix-vector product (v=A*u)
void MatVec(matrix &A, vector &u, vector &v);

// Use Jacobi's method to solve a linear system
void Jacobi(matrix &A, vector &b, vector &v, unsigned int &count, double tol=1e-6);

// Simple version of Jacobi's method to solve a linear system
void Jacobi2(matrix &A, vector &b, vector &v, unsigned int &count, double tol=1e-6);

// Use Gauss-Seidel method to solve a linear system
void GaussSeidel(matrix &A, vector &b, vector &v, unsigned int &count, double tol=1e-6);

int main(void )
{
   unsigned int N=3;

   matrix A(N);
   vector x(N), b(N);

   // Set up the linear system to solve
   for (unsigned int i=0; i<N; i++)
   {
      for (unsigned int j=0; j<N; j++)
	 if (i==j)
	    A.setij(i, j, (double)(N));
	 else A.setij(i,j, (double)(rand())/RAND_MAX);
      x.seti(i, 1.0);
   }




   MatVec(A, x, b);
   cout << "b=" << endl;
   b.print();


   cout << "A=" << endl;
   A.print();

   cout << "b=" << endl;
   b.print();

   vector est(N);
   unsigned int iterations;

   x.zero();
   Jacobi(A, b, x, iterations, 1e-6);
   cout << "Jacobi took " << iterations << " iterations. Solution is : " << endl;
   x.print();

   x.zero();
   Jacobi2(A, b, x, iterations, 1e-6);
   cout << "Jacobi2 took " << iterations << " iterations. Solution is : " << endl;
   x.print();

   x.zero();
   GaussSeidel(A, b, x, iterations, 1e-6);
   cout << "GS took " << iterations << " iterations. Solution is : " << endl;
   x.print();

}


//////////////////
//  Set v=A*u
void MatVec(matrix &A, vector &u, vector &v)
{
   unsigned int N;
   N = A.size();

   if ( (N != u.size()) || ( N != v.size() ) )
      cerr << "dimension mismatch in MatVec " << endl;
   else
   {
      for (unsigned int i=0; i<N; i++)
      {
         double x=0;
         for (unsigned int j=0; j<N; j++)
            x += A.getij(i,j)*u.geti(j);
         v.seti(i,x);
      }
   }
}

//  alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (vector &c, vector &a, vector &b, double alpha, double beta)
{
   unsigned int N;
   N = a.size();

   if ( (N != b.size()) )
      cerr << "dimension mismatch in VecAdd " << endl;
   else
   {
      for (unsigned int i=0; i<N; i++)
         c.seti(i, alpha*a.geti(i)+beta*b.geti(i) );
   }
}

// Use Jacobi's method to solve Ax=b,
// On entry : x is the initial guess
// On exit  : x is the estimate for the solution
void Jacobi(matrix &A, vector &b, vector &x,
   unsigned int &count, double tol)
{
   unsigned int N=A.size();
   count=0;
   if ( (N != b.size()) || (N != x.size() ) )
      cout << "Jacobi: error - A must be the same size as b,x\n";

   matrix Dinv(N), T(N);   // The diagonal and off-diagonal matrices

   for (unsigned int i=0; i<N; i++)
      for (unsigned int j=0; j<N; j++)
         if (j != i) {
            T.setij(i,j, -A.getij(i,j));
            Dinv.setij(i,j,0.0);
         }
         else {
            T.setij(i,j, 0.0);
            Dinv.setij(i,j, 1.0/A.getij(i,j));
         }

   // Now implement the algorithm:
   vector d(N), r(N);
   do
   {
      count++;
      MatVec(T,x,d);      // Set d=T*x
      VecAdd(d, b, d);    // set d=b+d (so d=b+T*x)
      MatVec(Dinv, d, x); // set x = inverse(D)*(b+T*x)

      MatVec(A, x, r);    // set r=A*x
      VecAdd(r, b, r, 1.0, -1.0); // set r=b-A*r

   }   while ( r.norm() > tol);
}


// Use Jacobi's method to solve Ax=b, just using nested for-loops
// On entry : x is the initial guess
// On exit  : x is the estimate for the solution
void Jacobi2(matrix &A, vector &b, vector &x,
   unsigned int &count, double tol)
{
   unsigned int N=A.size();
   count=0;
   if ( (N != b.size()) || (N != x.size() ) )
      cout << "Jacobi2: error - A must be the same size as b,x\n";

// Implement the Jacobi algorithm, using just for-loops
   vector  r(N), xnew(N);
   do  {
      count++;
      for (unsigned int i=0; i<N; i++)
      {
	 double t=b.geti(i);
	 for (unsigned int j=0; j<i; j++)
	    t-=A.getij(i,j)*x.geti(j);
	 for (unsigned int j=i+1; j<N; j++)
	    t-=A.getij(i,j)*x.geti(j);

	 xnew.seti(i, t/A.getij(i,i));

      }
      MatVec(A, xnew, r); // set r=A*x
      VecAdd(r, b, r, 1.0, -1.0); // set r=b-A*r

      VecAdd(x, x, xnew, 0.0, 1.0); // set x=xnew (lazy)
   }   while ( r.norm() > tol);
}



// Use the Gauss-Seidel method to solve Ax=b, just using nested for-loops
// On entry : x is the initial guess
// On exit  : x is the estimate for the solution
void GaussSeidel(matrix &A, vector &b, vector &x,
   unsigned int &count, double tol)
{
   unsigned int N=A.size();
   count=0;
   if ( (N != b.size()) || (N != x.size() ) )
      cout << "GaussSeidel: error - A must be the same size as b,x\n";

// Implement the GS algorithm, using just for-loops
   vector  r(N);
   do  {
      count++;
      for (unsigned int i=0; i<N; i++)
      {
	 double t=b.geti(i);
	 for (unsigned int j=0; j<i; j++)
	    t-=A.getij(i,j)*x.geti(j);
	 for (unsigned int j=i+1; j<N; j++)
	    t-=A.getij(i,j)*x.geti(j);

	 x.seti(i, t/A.getij(i,i));

      }
      MatVec(A, x, r); // set r=A*x
      VecAdd(r, b, r, 1.0, -1.0); // set r=b-A*r

   }   while ( r.norm() > tol);
}
