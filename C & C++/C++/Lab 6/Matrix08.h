/*Taidgh Murray
ID: 15315901
*/

#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include "Vector08.h"

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
   void print(void);
};

#endif
