#ifndef SIMPLE_LINKED_LIST__
#define SIMPLE_LINKED_LIST__
#include <iostream>

/*
 *  Author : Mouhamad KOREISSI
 *  Creation : Sunday 23 october 2016, 13:04
 * 
 *
 *  This is a tiny lib that implements a GENERIC simple linked list (single link)
*/

//Defining the structure of the list
template<typename T>
struct Node {
    T _data;
    Node<T> *_next;
};

//Basic operations on lists

template<typename T>
void headInsert (const T data, Node<T>* &list);

template<typename T>
void tailInsert (const T data, Node<T>* &list);

template<typename T>
void insert (const T data, int pos, Node<T>* &list);

template<typename T>
void headDelete (Node<T>* &list);

template<typename T>
void tailDelete (Node<T>* &list);

//Delete a specific element in the list
template<typename T>
void deleteL (const T data, Node<T>* &list);

template<typename T>
void printList (Node<T>* list);

template<typename T>
int size (Node<T>* list); 

void test();

#endif
