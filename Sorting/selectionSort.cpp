#include <iostream>

#define MIN 1000000000
#define SIZE 100

using namespace std;

int nbElements = -1; 

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

template <typename T>
T select(T *array, int begin, int end) {
    int selected = MIN;
    int i;

    for (i = begin; i < end; i++) {
        if (array[i] < selected)
            selected = array[i];
    }

    return selected;
}

template <typename T>
void insert(T *array, int element) {
    if (nbElements >= SIZE) return; //Return if overflowed

    nbElements++;
    int i;

    //Shifting all elements to right until element found
    for (i = nbElements; i >= 0; i--) {
        if (array[i - 1] > element)
            array[i] = array[i - 1];
        else {
            array[i] = element;
            break;
        }
    }
}

int main() {

    //int array[10] = {6, 3, 9, 8, 1, 5, 4, 2, 0, 0};
    int array[10] = {3, 5, 8, 9, 0, 0};
//    printf("begin : %d, end : %d, selected : %d\n", 5, 8, select(array, 5, 8));
    nbElements = 3;
    insert(array, 7);
    insert(array, 1);
    insert(array, 1);
    printArray(array, 10);
    return 0;
}
