#include <iostream>
#include <unistd.h>
#include "../stack.cpp"
#include "../util.h"

int main() {

    Stack<int> stack(5); //Creating a stack of Integers

    clear(); //Clearing the screen

    //Inserting 5 elements
    int i;
    for (i = 0; i < 5; i++) {
        cout << "\n\n\t" << GRN << "Push(" << i + 1 << ")" << RESET << endl << endl;
        stack.push(i + 1);        
        stack.print();
        usleep(1000000);
        clear();
    }
    
    if (stack.isFull())
        cout << "Stack is full now" << endl;
    else 
        cout << "Stack is still not full, you can insert more elements" << endl;

    //Deleting 5 elements
    for (i = 0; i < 5; i++) {
        cout << "\n\n\t" << GRN << "Pop ()" << RESET << endl << endl;
        stack.pop();
        stack.print();
        usleep(1000000);
        clear();
    }

    //Pushing 1 element
    stack.push(20); 

    if (stack.isEmpty()) 
        cout << "Stack is now empty" << endl;
    else
        cout << "Stack is not empty yet" << endl;

    //Flushing the stack
    stack.flush();

    if (stack.isEmpty()) 
        cout << "Stack is now empty" << endl;
    else
        cout << "Stack is not empty yet" << endl;


    return 0;
}
