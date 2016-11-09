#include <iostream>

using namespace std;

template <typename T>
static void swap2(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
static int partition(T *array, int low, int high) {
    T pivot = array[high];
    int wall = low;
    int current = low;

    for (current = low; current <= high; current++) {
        if (array[current] < pivot) {
            swap2(array[current], array[wall]);
            wall++;
        }
    }
    swap2(array[wall], array[high]);

    return wall;
}

template <typename T>
void quickSort(T *array, int low, int high) {
    if (low > high) return;
    int p = partition(array, low, high);

    quickSort(array, low, p-1);
    quickSort(array, p+1, high);

    return;
}

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

template <typename T>
bool assertSorted(T *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}

//Testing the program
int main() {

    //int array[9] = {6, 5, 1, 3, 8, 4, 7, 9, 2};
    //double array[9] = {6.2, 5.1, 1, 3, 8, 4, 7, 9, 2};
    //char array[9] = {'c', 'a', 'z', 'm', 'f', 'o', 'p', 'e', 'e'};
    string array[9] = {"c", "a", "z", "m", "f", "o", "p", "eo", "emz"};
    int size = 9;

    quickSort(array, 0, size - 1);

    //Asserting array's been sorted
    if (assertSorted(array, size)) cout << "OK\n";
    else  cout << "KO\n";
    
    printArray(array, size);
    return 0;
}
