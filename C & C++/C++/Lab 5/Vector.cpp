
#include <iostream>
#include <math.h>
using namespace std;

#include "Vector.h"

vector::vector (unsigned int Size) {
   N = Size;
   entries = new double[Size];
}

vector::~vector () {
   delete [] entries;
}

void vector::seti (unsigned int i, double x) {
   if (i<N)
      entries[i]=x;
   else
      cerr << "vector::seti(): Index out of bounds." << endl;
}

double vector::geti (unsigned int i) {
   if (i<N)
      return(entries[i]);
   else {
      cerr << "vector::geti(): Index out of bounds." << endl;
      return(0);
   }
}

void vector::print (void)
{
   for (unsigned int i=0; i<N; i++)
      cout << "[" << entries[i] << "]" << endl;
}

double vector::norm (void)
{
   double x=0;
   for (unsigned int i=0; i<N; i++)
      x+=entries[i]*entries[i];
   return (sqrt(x));
}

void vector::zero(void)
{
   for (unsigned int i=0; i<N; i++)
      entries[i]=0;
}
