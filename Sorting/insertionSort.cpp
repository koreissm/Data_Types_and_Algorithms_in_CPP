#include <iostream>

#define MIN 1000000000

using namespace std;

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

//Swapping two values
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void insertionSort(T *array, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        int tmp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

int main() {
    int array[8] = {6, 3, 9, 8, 1, 5, 4, 2};
    printf("Array before sorting : ");
    printArray(array, 8);

    //Sorting the array of size 8
    insertionSort(array, 8);

    printf("Array after being sorted : ");
    printArray(array, 8);
    
    return 0;
}
