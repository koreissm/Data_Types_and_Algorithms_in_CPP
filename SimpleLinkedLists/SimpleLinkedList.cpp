#include "SimpleLinkedList.h"
#include <assert.h>

using namespace std;

template<typename T>
void headInsert (const T data, Node<T>* &list) {
    //Creating a new node
    Node<T>* node = new Node<T>;
    node->_data = data;
    node->_next = list;

    //Inserting the node to the head
    list = node;
}

template<typename T>
void tailInsert (const T data, Node<T>* &list) {
    Node<T>* listCopy = list;
    //Creating a new node
    Node<T>* node = new Node<T>;
    node->_data = data;
    node->_next = nullptr;

    //Going to the end of the list
    while (listCopy->_next != nullptr) {
        listCopy = listCopy->_next;
    }

    //Inserting the new node
    listCopy->_next = node;
}

template<typename T>
void insert (const T data, int pos, Node<T>* &list) {
    //Proceding by recursion
    if (pos == 0) {
        headInsert(data, list);
    }
    else {
        insert(data, pos - 1, list->_next);
    }
}


template<typename T>
void headDelete (Node<T>* &list) {
    list = list->_next;
}

template<typename T>
void tailDelete (Node<T>* &list) {
    Node<T> *beforeLast = list, *last = list->_next;
    if (list->_next == nullptr) {list = nullptr;} //List with one element
    else {
        //Going the end of the list
        while (last->_next != nullptr) {
            beforeLast = last;
            last = last->_next;
        }

        //Removing the last element of the list
        beforeLast->_next = nullptr;
    }
}

template<typename T>
void deleteL (const T data, Node<T>* &list) {
    Node<T>* listCopy = list->_next, *before = list;
    //Searching the element we want to delete
    while (listCopy != nullptr && listCopy->_data != data) {
        before = listCopy;
        listCopy = listCopy->_next;
    }

    //Delete the actual element
    if (listCopy != nullptr) {
        before->_next = listCopy->_next;
    }
}

template<typename T>
void printList (Node<T>* list) {
    int l = 0;
    cout << "Current state of the list : ";
    if (list == nullptr) {cout << "EMPTY";}
    while (list != nullptr) {
        cout << list->_data <<  ", ";
        list = list->_next;
        l++;
    }
    cout << endl;
}

template<typename T>
int size (Node<T>* list) {
    int l = 0;
    while (list != nullptr) {
        l++;
        list = list->_next;
    }
    cout << "Size : " << l << endl;

    return l;
}

void test () {

    Node<int>* list = new Node<int>; //Creating a list
    list->_next = nullptr;
    list->_data = 9;

    //Inserting the numbers 3, 4, 5, 6, 9 in the tail of the list
    headInsert(6, list); 
    headInsert(5, list); 
    headInsert(4, list); 
    headInsert(3, list); 
    cout << "\t\t5 head insertion and 1 tail insertion" << endl;
    tailInsert(10, list); 

    printList(list);
    
    assert(size(list) == 6); //Checking the size of the list
    //List current state : 3, 4, 5, 6, 9, 10

    //Removing 1 element in head and 1 in the tail
    headDelete(list);
    tailDelete(list);
    cout << "\t\t1 head deletion and 1 tail deletion" << endl;
    printList(list);
    assert(size(list) == 4);
    //list current state : 4, 5, 6, 9

    //Inserting 10 to the 2nd position
    insert(12, 2, list);
    cout << "\t\t1 insertion in pos P" << endl;
    assert(size(list) == 5);
    //list current state : 4, 12, 5, 6, 9
    printList(list);
    
    //Removing 5 from the list
    deleteL(5, list);
    cout << "\t\t1 deletion in pos P" << endl;
    printList(list);
    assert(size(list) == 4);
    //List current state : 4, 12, 6, 9

    delete list;
}
