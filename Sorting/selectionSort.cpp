#include <iostream>

#define MIN 1000000000
#define SIZE 100

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
void selectionSort(T *array, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        //Searching for the min in the right of the array
        int min = MIN;
        int index = -1;
        for (j = i; j < size; j++) {
            if (array[j] < min) {
                min = array[j];
                index = j;
            }
        }

        //Swapping
        swap(array[i], array[index]);
    }
}

int main() {
    int array[8] = {6, 3, 9, 8, 1, 5, 4, 2};
    printf("Array before sorting : ");
    printArray(array, 8);

    //Sorting the array of size 8
    selectionSort(array, 8);

    printf("Array after being sorted : ");
    printArray(array, 8);
    
    return 0;
}
