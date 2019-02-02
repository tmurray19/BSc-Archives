//lab4.cpp
#include <iostream>
#include<fstream>
#define MAX_STACK 100000
using namespace std;

//Bringing stack function from lab3
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



int main(){
    //variable declaration
    ifstream f;
    char c;
    int lines = 0;
    int counter = 0;
    string str, stringer;
    stack bracketChecker;

    //asking user for file name
    cout << "Enter file to open: ";
    cin >> str;

    //opens file for reading
    f.open(str);

    //stops program if file can't be opened
    if(f.fail()){
        cerr << "Failure opening file" << endl;
        return 0;
    }

    //counts number of lines in file
    while(!(f.eof())){
        getline(f, stringer);
        lines++;
    }

    //closes file so that it can be opened freshly in a new for loop instance
    f.close();


    f.open(str);

    //this loop adds all brackets to a stack
    while(!(f.eof())){

        f.get(c);
        cout << c;

        if(c == '('){
            bracketChecker.push(c);
        }

        if(c == '['){
            bracketChecker.push(c);
        }

        if(c == '{'){
            bracketChecker.push(c);
        }

    }

    f.close();

    f.open(str);

    //this loop compares the characters to the stack
    while(!(f.eof())){
        f.get(c);

        /*if a comment character shows up, the code ignores the line (it ignores every character until
        a new line character shows up)*/

        if(c == '/'){
            f.ignore(128, '\n');
        }

        if(c == ')'){
            if(bracketChecker.pop() == '('){
                continue;
            }
            else{
                cout << "() doesn't match";
                return 0;
            }
        }

        else if(c == ']'){
            if(bracketChecker.pop() == '['){
                continue;
            }else{
                cout << "[] doesn't match";
                return 0;
            }
        }

        else if(c == '}'){
            if(bracketChecker.pop() == '{'){
                continue;
            }
            else{
                cout << "{} doesn't match";
                return 0;
            }
        }

        else{
                f.ignore();
        }
    }

    //gives a warning to the user saying that the stack has not been emptied
    if(!(bracketChecker.is_empty())){
        cerr << "Error: Stack not emptied." << endl;
    }

    //prints out the amount of lines parsed
    cout << "Program parsed. There was " << lines << " lines checked. No issues found." << endl;
    return 0;
}
