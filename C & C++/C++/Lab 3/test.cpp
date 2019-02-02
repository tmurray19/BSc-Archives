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
        return NULL;
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
    //Q3
    //Decimal to Binary
    unsigned int num=0;
    int holder=0;

    cout << "Enter a number in decimal to be converted to binary:" << endl;
    cin >> num;

    stack stacker3(num*2);

    while(num>0){
            holder = num % 2;
            num /= 2;
            stacker3.push(holder);
            if(stacker3.is_full()){
                    break;
            }
    }

    while(!(stacker3.is_empty())){
            cout << stacker3.pop();
    }

    return (0);
}
