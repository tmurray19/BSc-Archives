
class matrix {
private:
   double *entries;
   unsigned int N;
public:
   matrix (unsigned int Size=2);
   ~matrix(void) { delete [] entries; };

   unsigned int size(void) {return (N);};
   double getij (unsigned int i, unsigned int j);
   void setij (unsigned int i, unsigned int j, double x);

   void print(void);
};

