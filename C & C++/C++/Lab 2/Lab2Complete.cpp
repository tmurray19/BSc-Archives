using namespace std;
//Bisection function

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

//defining questions as functions
double Q1(double a)
{
   double b = 10-a;
   return( a*sqrt(b) );
}

double Q2(double t)
{
   double P1=500*t, P2 = 100-800*t;
   return(-sqrt ( P1 * P1 + P2 * P2 ) );
}

//declaring determination criterion as a global value
double Bound;


//defining bisection function as a recursive
double recursive_bisection(double ObjectiveFunction(double), double a, double b, unsigned int &iter, unsigned int Maxiter){
   double c = (a+b)/2.0;
   if (((b-a) < Bound) || (iter >= Maxiter)){
      return(c);
    }
   else
   {
       //increment iteration counter iter (initialised as 0 in main)
      iter++;
      //defining left and right values
      double l = (a+c)/2.0, r=(c+b)/2.0;

      //if the mid point is larger than both left and right values, the function is called again, but with l & r instead of a & b
      if ( (ObjectiveFunction(c) > ObjectiveFunction(l)) && (ObjectiveFunction(c) > ObjectiveFunction(r)) )
	 return( recursive_bisection(ObjectiveFunction, l, r, iter, Maxiter) );

	 //if the left is larger than the right, the right side is discarded, and the function is called on the left side
      else if ( ObjectiveFunction(l) > ObjectiveFunction(r) )
	 return( recursive_bisection(ObjectiveFunction, a, c, iter, Maxiter) );

	 //otherwise, the right side is worked on
      else
	 return( recursive_bisection(ObjectiveFunction, c, b, iter, Maxiter) );
   }
}



//main function
int main(void){
   double a, b, c;
   unsigned int iter=0, Maxiter=40;


   cout << "Enter the desired bound value: ";
   cin  >> Bound;

   //Q1
   cout << "Q1: \n";

   a=0; b=10;
   iter=0;
   c = recursive_bisection(Q1, a, b, iter, Maxiter);

   cout << "The maximum of the function a*sqrt(b) is when a=" << c << " and b=" << 10-c << ".";
   cout << "\nThe recursive_bisection() function took " <<  iter << " iter.\n";
   cout << endl;

   if (iter >= Maxiter){
       cout << Maxiter << " Iterations reached. Termiating";
       return 0;
   }

   //Q2
   cout << "Q2: \n" ;
   iter=0;
   a=0; b=10;
   c = recursive_bisection(Q2, a,b, iter, Maxiter);

   cout << "Min distance between P1 and P2:" << setprecision(6) << -Q2(c) << "km.";
   cout << "\nOccurs at time t=" << c << " hours.";
   cout << "\nThe recursive_bisection() function took " <<  iter << " iter.\n";
   cout << endl;

  if (iter >= Maxiter){
       cout << Maxiter << " Iterations reached. Termiating";
       return 0;
   }

   return(0);
}


