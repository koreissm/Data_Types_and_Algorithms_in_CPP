#include "stack.h"

using namespace std;
template <class T>
Stack<T>::Stack(const int size) : _size(size) {
    _peek = 0;
    _data = new T[size];
}

template <class T>
bool Stack<T>::isEmpty() {
    return (_peek == 0);
}

template <class T>
bool Stack<T>::isFull() {
    return _peek >= _size;
}

template <class T>
void Stack<T>::push(T element) {
    _data[_peek++] = element;
}

template <class T>
void Stack<T>::pop() {
    _peek--;
}

template <class T>
T Stack<T>::peek() {
    return _data[_peek];
}

template <class T>
void Stack<T>::flush () {
    _peek = 0;
}

template <class T>
void Stack<T>::print() {
    int i;
    cout << "\tStack's current state\n\n";
    for (i = _peek - 1; i >= 0; i--) {
        cout << BLU << _data[i] << RESET;
        if (i == _peek - 1) cout << RED << "\t<----- PEEK" << RESET;
        if (i == 0) continue;
        cout << "\n^" << endl;
    }
    cout << endl;
}
