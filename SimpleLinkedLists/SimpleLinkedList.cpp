#include "SimpleLinkedList.h"

using namespace std;


void headInsert (const int data, Node* &list) {
    //Creating a new node
    Node* node = new Node;
    node->_data = data;
    node->_next = list;

    //Inserting the node to the head
    list = node;
}


void tailInsert (const int data, Node* &list) {
    Node* listCopy = list;
    //Creating a new node
    Node* node = new Node;
    node->_data = data;
    node->_next = nullptr;

    //Going to the end of the list
    while (listCopy->_next != nullptr) {
        listCopy = listCopy->_next;
    }

    //Inserting the new node
    listCopy->_next = node;
}


void insert (const int data, int pos, Node* &list) {
    //Proceding by recursion
    if (pos == 0) {
        headInsert(data, list);
    }
    else {
        insert(data, pos - 1, list->_next);
    }
}


void headDelete (Node* &list) {
    list = list->_next;
}


void tailDelete (Node* &list) {
    Node *beforeLast = list, *last = list->_next;
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


void deleteL (const int data, Node* &list) {
    Node* listCopy = list->_next, *before = list;
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


void printList (Node* list) {
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


int size (Node* list) {
    int l = 0;
    while (list != nullptr) {
        l++;
        list = list->_next;
    }
    cout << "Size : " << l << endl;

    return l;
}
