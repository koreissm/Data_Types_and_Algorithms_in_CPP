#include <iostream>

#define MAX 1000

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

template <class T>
class Stack {
    private:
        const int _size;
        T *_data;
        int _peek;
     
    public:
        Stack(const int size); 

        bool isEmpty(); 

        bool isFull(); 

        void push(T element);

        void pop(); 

        T peek(); 

        void flush();

        void print();

};
