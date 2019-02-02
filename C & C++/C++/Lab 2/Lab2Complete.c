using namespace std;
//Bisection function

double Q1(double a)
{
   double b = 10-a;
   return( a*sqrt(b) );
}

double Q2(double t)
{
   double P1=500*t, P2 = 100-800*t;
   return( -sqrt(P1*P1 + P2*P2) );
}

double Bound;

int main(void)
{
   double a, b, c;
   unsigned int iterations=0, MaxIterations=40;

   cout << "Enter the desired bound: ";
   cin  >> Bound;

   // For Objective function Q1
   cout << "Q1: \n"

   a=0; b=10;
   iterations=0;
   c = recursive_bisection(Q1, a, b, iterations, MaxIterations);

   cout << "The maximum of the function a*sqrt(b) is when a="
	<< c << " and b=" << 10-c;
   cout << "\nrecursive_bisection() took " <<  iterations << " iterations.\n";

   if (iterations >= MaxIterations)
   {
       cout << MaxInterations << " iterations reached. Termiating";
       return 0;
   }

   // For Objective function Q2
   cout << "Q2: \n" ;
   iterations=0;
   a=0; b=10;
   c = recursive_bisection(Q2, a,b, iterations, MaxIterations);

   cout << "The minimum distance between P1 and P2 is " << setprecision(6) << -Q2(c) << "km.";
   cout << "\nThis occurs at time t=" << c << " hours.";
   cout << "recursive_bisection() took " <<  iterations << " iterations.\n";

  if (iterations >= MaxIterations)
   {
       cout << MaxInterations << " iterations reached. Termiating";
       return 0;
   }

   return(0);
}

double recursive_bisection(double ObjFn(double), double a, double b, unsigned int &iterations, unsigned int MaxIterations){
   double c = (a+b)/2.0;
   if (((b-a) < Bound) || (iterations >= MaxIterations)){
      return(c);
    }
   else
   {
      iterations++;
      double l = (a+c)/2.0, r=(c+b)/2.0;

      if ( (ObjFn(c) > ObjFn(l)) && (ObjFn(c) > ObjFn(r)) )
	 return( recursive_bisection(ObjFn, l, r, iterations, MaxIterations) );

      else if ( ObjFn(l) > ObjFn(r) )
	 return( recursive_bisection(ObjFn, a, c, iterations, MaxIterations) );

      else
	 return( recursive_bisection(ObjFn, c, b, iterations, MaxIterations) );
   }
}
