/* FILE  : Lab1-Q5.cpp
   Author: Niall Madden
   Date  : 23/01/17
   For   : CS319, Lab 1
   What  :  Find the largest integer correctly representable,
            and time how long it takes.
*/

#include <iostream>
#include <time.h>

int main(void)
{
   std::cout << std::endl <<
      "-------------------------------\n" <<
      "| CS319  Lab 1, Q5,  01/02/18 |\n" <<
      "------------------------------\n";

   long int i, j;
   clock_t start;
   float diff, diff_seconds;
   start=clock();

   i=1;
   j=i+1;
   while ( i<j )
   {
      i++;
      j=i+1;
   }
   diff = (float)(clock()-start);
   diff_seconds = diff/CLOCKS_PER_SEC;
   std::cout << "Overflow at i="<< i
	     << std::endl;
   std::cout << "Computation took "
	     << diff_seconds << " seconds."
	     << std::endl;
   return(0);
}
