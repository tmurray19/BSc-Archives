//including libraries for use in the questions
#include<iostream>
#include<math.h>
#include<limits>
#include<iomanip>
using namespace std;

//Question 1
int q1(void ){
    //declaring int a and assigning the value of 9 to it
    int a = 9;

    //a = -a  (Should equal -9)
    a=-a;
    cout << "a = -a: " << a << endl;

    //--a (decrements a by 1, resulting in -10)
    cout << "--a = " << --a << endl;

    //a-=a (Same as 9-9, which equals 0)
    a-=a;
    cout << "a-=a = " << a << endl;

    //a=(a==a) (a should be equal to 1, indicating True)
    cout << "a=(a==a): " << "a=" << (a == a) << endl;

}

int q2(void ){
    cout << endl;
    //initialise value
    int n;
    //ask user for input
    cout << "Enter integer beween 1 & 19: ";
    cin >> n;
    //check if n is between 1 and 19
    //then calculates and shows 3^n for all n
    //otherwise prints error
    if(n>=1 && n<=19)
        for(int i=1; i<=n; i++)
            cout << "3^" << i << setw(2) << right << "=" << setw(15) << right << pow(3,i) << endl;
    else
        cout << "Error. Number not in scope." <<endl;
}

int q3(void ){
    cout << endl;
    //initialise values
    float itemCost;
    int vatType;
    //askk user for inputs
    cout << "Enter cost of item: " << endl;
    cin >> itemCost;
    cout << "Choose VAT type (1 = Standard (23%) ,2 = Reduced (13.5%),3 = Tourism (9%),4 = Livestock (4.8%), 5 = Zero (0%)" << endl;
    cin >> vatType;
    cout << "Calculating...\n";
    //calculate item + vat based off input from user
    //uses a number of if statements to check the type of vat
    if(vatType==1)
        cout << "€" << itemCost + (itemCost * .23) << endl;
    else if(vatType==2)
        cout << "€" << itemCost + (itemCost * .135) << endl;
    else if(vatType==3)
        cout << "€" << itemCost + (itemCost * .09) << endl;
    else if(vatType==4)
        cout << "€" << itemCost + (itemCost * .048) << endl;
    else if(vatType==5)
        cout << "€" << itemCost << endl ;
    else
        cout << "Invalid input.";
}

int q4(void ){
    cout << endl;
    //initialise values
    float itemCost;
    int vatType;
    //askk user for inputs
    cout << "Enter cost of item: " << endl;
    cin >> itemCost;
    cout << "Choose VAT type (1 = Standard (23%) ,2 = Reduced (13.5%),3 = Tourism (9%),4 = Livestock (4.8%), 5 = Zero (0%)" << endl;
    cin >> vatType;
    cout << "Calculating...\n";
    //calculate item + vat based off input from user
    //checks the case off the vatType variable
    //then switched the case based off this number
    switch(vatType){
        case 1:cout << "€" << itemCost + (itemCost * .23) << endl; break;
        case 2:cout << "€" << itemCost + (itemCost * .135) << endl; break;
        case 3:cout << "€" << itemCost + (itemCost * .09) << endl; break;
        case 4:cout << "€" << itemCost + (itemCost * .048) << endl; break;
        case 5:cout << "€" << itemCost << endl ; break;
    }

}

int q5(void ){
    /*(a) there is an integer overflow at i = 2147483647.
    This can be written as 2^31-1.
    The max value for an int is 2^31-1 (ints are 32 bits), which is why there's an overflow.
    The results agree with what was covered in the exams.
    */

    /*(b)
    short int - overflow at i = 32767.
    This can be written as 2^15-1.
    This is the max value for a short int => 2^15-1 (short ints are 16 bits)

    unsigned int - overflow at i = 4294967295.
    This can be written as 2^32-1.
    This the max value for an unsigned int => 2%32-1 (unsigned ints are 32 bits)
    */

    /*(c)
    On my laptop, which has a ~2.2Ghz process (with 2 cores), this program takes roughly
    10 seconds, on average. As the processor has a lower frequency, it takes longer to
    overflow the int value. We can see that the higher the frequency of a processor, the
    more calculations it can handle per tick.
    */

    /*(d)
    The largest possible int type in c++ is a 64 bit integer. Therefore, I think that it'll
    take roughly twice as long as previously, in other words about 20 seconds.
    */
}

int q6(void ){
    //divides x/2 as long as it's over 0
    //a printout for each x is given to see the smallest value possible

    cout << endl;
    float x = 1.0;
    while(x>0){
        x /= 2;
        cout << x << endl;
    }
}

int q7(void ){
    //multiplys x by zero as long as x is still a finite value
    //a printout for each x is given to see the largest value possible
    cout << endl;
    float x = 1.0;
    while(isfinite(x)){
        x*=2;
        cout << x << endl;
    }
}

int q8(void ){
    cout << endl;

    //initialising and assigning variables
    double smallVar = 1.0;
    double largeVar = 1.0;
    double x = 1.0;

    //calculating smallest positive double value
    cout << "Smallest positive double - calculation:" << endl;
    while(smallVar>0){
        smallVar /= 2;
        cout << smallVar << endl;
    }
    //comparing it to the library value
    cout << "Smallest positive double - library =" << std::numeric_limits<double>::denorm_min() << endl;

    //calculating largest postive double value
    cout << "Largest positive double - calculation: " << endl;
    while(isfinite(largeVar)){
        largeVar *= 2;
        cout << largeVar << endl;
    }
    //comparing to library value
    cout << "Largest positive double - library =" << std::numeric_limits<double>::max() << endl;


    //calculating largest x, where 1 != 1+x
    while(1 != 1+x){
        x /= 2;
    }
    cout << "x = " << x << endl;

}


//main to run all questions
int main(){
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
    q7();
    q8();
    return 0;
}
