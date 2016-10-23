#include <iostream>

/*
 *  Author : Mouhamad KOREISSI
 *  Creation : Sunday 23 october 2016, 13:04
 * 
 *
 *  inthis is a tiny lib that implements a GENERIC simple linked list (single link)
*/

//Defining the structure of the list

struct Node {
    int _data;
    Node *_next;
};

//Basic operations on lists


void headInsert (const int data, Node* &list);


void tailInsert (const int data, Node* &list);


void insert (const int data, int pos, Node* &list);


void headDelete (Node* &list);


void tailDelete (Node* &list);

//Delete a specific element in the list

void deleteL (const int data, Node* &list);


void printList (Node* list);


int size (Node* list); 
