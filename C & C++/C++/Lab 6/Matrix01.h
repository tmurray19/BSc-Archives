// Matrix01.h:  For CS319 Week 8
//   What: Header file for matrix class, including overloading = and *
// Author: Niall Madden
//   Date: March 2016
// Note: Implementation for a square matrix

#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include "Vector.h"

class matrix {
private:
   double *entries;
   unsigned int N;
public:
   matrix (unsigned int Size=2);
   matrix (const matrix &m); // New copy constructor
   ~matrix(void);

   matrix &operator=(const matrix &B); // overload assignment operator

   unsigned int size(void) {return (N);};
   double getij (unsigned int i, unsigned int j);
   void setij (unsigned int i, unsigned int j, double x);

   vector operator*(vector u);
   friend vector operator/(vector u, matrix L);

   void print(void);
};

#endif
