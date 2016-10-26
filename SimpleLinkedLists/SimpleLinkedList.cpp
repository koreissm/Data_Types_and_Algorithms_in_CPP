#include "SimpleLinkedList.h"
#include <assert.h>

using namespace std;

template<typename T>
int empty (Node<T>* &list) {
    return list == nullptr;
}

template<typename T>
void add (const T data, Node<T>* &list) {
    //Creating a new node
    Node<T>* node = new Node<T>;
    node->_data = data;
    node->_next = list;

    //Inserting the node to the head
    list = node;
}

template<typename T>
void add_last (const T data, Node<T>* &list) {
    Node<T>* listCopy = list;
    //Creating a new node
    Node<T>* node = new Node<T>;
    node->_data = data;
    node->_next = nullptr;

    //Going to the end of the list
    while (!empty(listCopy->_next)) {
        listCopy = listCopy->_next;
    }

    //Inserting the new node
    listCopy->_next = node;
}

template<typename T>
void insert (const T data, int pos, Node<T>* &list) {
    //Proceding by recursion
    if (pos == 0) {
        add(data, list);
    }
    else {
        insert(data, pos - 1, list->_next);
    }
}


template<typename T>
T pop (Node<T>* &list) {
    T element = list->_data;
    list = list->_next;

    return element;
}

template<typename T>
T pop_last (Node<T>* &list) {
    T element;
    Node<T> *beforeLast = list, *last = list->_next;
    if (empty(list->_next)) {list = nullptr;} //List with one element
    else {
        //Going the end of the list
        while (!empty(last->_next)) {
            beforeLast = last;
            last = last->_next;
        }

        //Removing the last element of the list
        element = last->_data;
        beforeLast->_next = nullptr;
    }
    return element;
}

template<typename T>
void deleteL (const T data, Node<T>* &list) {
    Node<T>* listCopy = list->_next, *before = list;
    //Searching the element we want to delete
    while (!empty(listCopy) && listCopy->_data != data) {
        before = listCopy;
        listCopy = listCopy->_next;
    }

    //Delete the actual element
    if (!empty(listCopy)) {
        before->_next = listCopy->_next;
    }
}

template<typename T>
void print (Node<T>* list) {
    int l = 0;
    cout << "Current state of the list : ";
    if (list == nullptr) {cout << "EMPTY";}
    while (!empty(list)) {
        cout << list->_data <<  ", ";
        list = list->_next;
        l++;
    }
    cout << endl;
}

template<typename T>
int size (Node<T>* list) {
    int l = 0;
    while (!empty(list)) {
        l++;
        list = list->_next;
    }
    cout << "Size : " << l << endl;

    return l;
}

