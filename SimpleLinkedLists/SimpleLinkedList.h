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
    
    //Basic operations on lists

    void add (const T data, Node<T>* &list); //Adds an element in the head of the list

    void add_last (const T data, Node<T>* &list);

    void insert (const T data, int pos, Node<T>* &list);

    T pop (Node<T>* &list); //Remove an element from the head of the list

    T pop_last (Node<T>* &list);

    void deleteL (const T data, Node<T>* &list); //Delete a specific element in the list

    void print (Node<T>* list);

    int size (Node<T>* list); 

};

#endif
