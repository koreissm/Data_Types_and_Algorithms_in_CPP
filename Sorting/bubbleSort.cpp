#include <iostream>

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
void bubbleSort(T *array, int size) {
    int i;
    bool swapped = true;

    //Performing the algo while a swap has been done
    while (swapped) {
        swapped = false;
        for (i = 0; i < size; i++) {
            if (array[i] > array[i + 1] && i < size - 1) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
    }
}

int main() {
    int array[8] = {6, 3, 9, 8, 1, 5, 4, 2};
    printf("Array before sorting : ");
    printArray(array, 8);

    //Sorting the array of size 8
    bubbleSort(array, 8);

    printf("Array after being sorted : ");
    printArray(array, 8);
    
    return 0;
}
