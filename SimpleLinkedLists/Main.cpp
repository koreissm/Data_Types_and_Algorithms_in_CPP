#include "SimpleLinkedList.cpp"
#include <assert.h>

using namespace std;

int main() {

    Node<int>* list = new Node<int>; //Creating a list
    list->_next = nullptr;
    list->_data = 9;

    //Inserting the numbers 3, 4, 5, 6, 9 in the tail of the list
    add(6, list); 
    add(5, list); 
    add(4, list); 
    add(3, list); 
    cout << "\t\t5 head insertion and 1 tail insertion" << endl;
    add_last(10, list); 

    print(list);
    
    assert(size(list) == 6); //Checking the size of the list
    //List current state : 3, 4, 5, 6, 9, 10

    //Removing 1 element in head and 1 in the tail
    pop(list);
    pop_last(list);
    cout << "\t\t1 head deletion and 1 tail deletion" << endl;
    print(list);
    assert(size(list) == 4);
    //list current state : 4, 5, 6, 9

    //Inserting 10 to the 2nd position
    insert(12, 2, list);
    cout << "\t\t1 insertion in pos P" << endl;
    assert(size(list) == 5);
    //list current state : 4, 12, 5, 6, 9
    print(list);
    
    //Removing 5 from the list
    deleteL(5, list);
    cout << "\t\t1 deletion in pos P" << endl;
    print(list);
    assert(size(list) == 4);
    //List current state : 4, 12, 6, 9

    delete list;
    return 0;
}
