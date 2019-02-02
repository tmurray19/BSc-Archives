#include <iostream>
#define MAX_STACK 50

using namespace std;

//Class constructor
class stack {
    //variables are privately declared to avoid unwanted editing
    private:
        char *contents;
        int top;
    //public functions are declared to edit the variables
    public:
        stack (void);
        ~stack (void);
        stack (unsigned int StackSize);
        void init(void);
        void push(char c);
        char pop(void);
        bool is_empty(void);
        bool is_full(void);
};

//Stack constructor method
stack::stack(void){
    top=0;
    contents = new char[MAX_STACK];
}

stack::stack(unsigned int StackSize){
    top=0;
    contents = new char[StackSize];
}

//Destructor method ( Q1, (i) )
stack::~stack(void){

}

//Push function, to add a character to the top of the stack
void stack::push(char c){
    if (top == MAX_STACK){
        cerr << "Stack is full." << endl;
    }
    else{
        contents[top]=c;
        top++;
    }
}

//Pop function, to remove a character from the stack
char stack::pop(void){
    if(top == 0){
        cerr << "Cannot pop an empty stack" << endl;
        return 0;
    }
    else{
        top--;
        return(contents[top]);
    }
}

//Check to see if a stack s is empty (if the top value is 0, it is empty)
bool stack::is_empty(void){
    if(top == 0){
        return true;
    }
    else{
        return false;
    }
}

//Check to see if stack is full (if top value is as large as MAX_STACK)
bool stack::is_full(void){
    if(top == MAX_STACK){
        return true;
    }
    else{
        return false;
    }
}


//Main function, which has all attempts for Q3
int main(void ){

    //PART 3
    //Q1
    //Palindrome checker
    string str;
    cout << "Please enter a string you wish to check: " << endl;
    cin >> str;

    //initialise stack
    stack stacker(str.length());

    //Pushes string to stack
    for(int i=0; i<str.length();i++){
        stacker.push(str[i]);
    }

    //Pop stack, and compare it to str
    for(int l=0; l<str.length(); l++){
        //code in while loop only runs as long as the popped char is not the same as the
        //corresponding l'th value of the str string
        while(! (stacker.pop() == str[l] ) ){
            cerr << "Not a palindrome." << endl;
            return 0;
        }
    }

    //Prints out that the string is a palindrome
    cout << "Palindrome." << endl;

    //Q2
    //Equation checker
    string eqn;
    cout << "Enter equation you want to check:" << endl;
    cin >> eqn;

    //initialise count values
    int counter = 0;

    //initialise stack with lenght of equation
    stack stacker2(eqn.length());

    //better attempt at parser code
    //pushes opening brackets to a stack
    //if a closing bracket shows up, it compares to the stack
    //if its true, the code continues
    //otherwise the program terminates
    for(int h=0; h<eqn.length();h++){
            if(eqn[h] == '('){
                stacker2.push(eqn[h]);
               }
            else if(eqn[h] == ')'){
                if((stacker2.pop() == '(')){
                        continue;
                    }
            }else{
                cerr << "Incorrect equation entered." << endl;
                return 0;
            }
    }
    //if the amount of opening and closing brackets are the same, then the program
    cout << "Equation parsed correctly" << endl;

    //Q3
    //Decimal to Binary
    unsigned int num=0;
    int holder=0;

    //asks user for number to be inputted
    cout << "Enter a number in decimal to be converted to binary:" << endl;
    cin >> num;

    //creates a stack with size of the number inputted
    stack stacker3(num);

    //while the number is greter than 0, the holder value is assigned to the
    //modulo division of the num value by 2. The num value is also divided by 2
    //The holder value is pushed to the stack stacker3.
    //If the stack gets full, the loop breaks

    //for some reason, despite following the algorithm, the output is incorrect.
    //I don't know how to fix this, it just prints out ascii characters
    while(num>0){
            holder = num % 2;
            stacker3.push(holder);

            if(stacker3.is_full()){
                    break;
            }
            num /= 2;
    }

    //while the stack isn't empty, the loop prints out each popped value
    while(!(stacker3.is_empty())){
        cout << stacker3.pop() << endl;
    }

    return (0);
}
