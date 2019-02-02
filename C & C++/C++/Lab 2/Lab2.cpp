//Bisection function
#include<bits/stdc++.h>
using namespace std;
//global definition of 10^-6 interval (a)
#define ERROR 0.000001

//Define the function to be calculated here
double f(double x){
    return(exp(x) - 3*x*x + 2*x);
}

// Prints root of f(x) with error of ERROR
void bisection(double a, double b, double ObjFunc(double n)){
    //in case any input mistakes are made, exits the code with an
    //error message
    if (f(a) * f(b) >= 0){
        cout << "A & B are incorrect\n";
        return;
    }

    double c = a;
    //long int because we might need to store a large number of iteration
    long int counter = 0;
    while ((b-a) >= ERROR){
        //Increment counter
        counter++;

        //Find middle point
        c = (a+b)/2;

        //Check if middle point is root
        if (f(c) == 0.0){
            break;
        }
        //break if too many increments
        else if(counter>100){
            cout << "Too many increments";
            break;
        }
        //Decide the side to repeat the steps
        else if (f(c)*f(a) < 0){
            b = c;
        }
        else{
            a = c;
        }
    }
    cout << "Final Value: " << c;
    cout << "\nCounter: " << counter;
}

//Main function
int main(){
    //Define values a & b, a<b
    double a =-200, b = 300;
    //Call bisection algoritm
    bisection(a, b);
    return 0;
}



//an attempt at the recursive version of the bisection algorithm (d)
void bisection_recursive_version(double a, double b){
    //in case any input mistakes are made, exits the code with an
    //error message
    if (f(a) * f(b) >= 0){
        cout << "A & B are incorrect\n";
        return;
    }

    //get midpoint of a & b,  c
    double c = (a+b)/2.0;
    //ged midpoint of data set to the left and right of c, labelled l & r
    double l=(a+c)/2.0, r=(c+b)/2.0;

    // int because we might need to store a large number of iteration (b)
    long int counter = 0;

    //clause for if the counter gets too high (c) [number may be too high]
    if(counter>500){
        cout << "Too many iterations.";
        return;
    }

    else if((b-a)<=ERROR){
        counter++;
        cout << "Final Value: " << c;
    }
    else{
        if( f(c)>f(l) && f(c)>f(r) ){
            a=l;
            b=r;
            bisection_recursive_version(a, b);
        }
        else if(f(l) > f(r) ){
            b=c;
            bisection_recursive_version(a, b);
        }
        else{
            a=c;
            bisection_recursive_version(a, b);
        }
    }
}
