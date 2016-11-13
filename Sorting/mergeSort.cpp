#include <iostream>

using namespace std;

int size = 9;
int arr[9] = {6, 5, 1, 3, 8, 4, 7, 9, 2};
int newArray[9];
//double array[9] = {6.2, 5.1, 1, 3, 8, 4, 7, 9, 2};
//char array[9] = {'c', 'a', 'z', 'm', 'f', 'o', 'p', 'e', 'e'};
//string array[9] = {"c", "a", "z", "m", "f", "o", "p", "eo", "emz"};


void merge(int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    
    while (i <= mid && j <= hi) {
        if (arr[i] < arr[j]) {
            newArray[k++] = arr[i++];
        }
        else {
            newArray[k++] = arr[j++];
        }
    }

    //If array1 bigger than array2
    while (i <= mid) {
        newArray[k++] = arr[i++];
    }
    //If array2 bigger than array1
    while (j <= hi) {
        newArray[k++] = arr[j++];
    }

    //Updating the old array
    for (i = lo; i <= hi; i++)
        arr[i] = newArray[i];

}

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

void mergeSort(int lo, int hi) {
    if (lo < hi) {
    
    int middle = (hi + lo) / 2;

    mergeSort(lo, middle);
    mergeSort(middle + 1, hi);

    merge(lo, middle, hi);    
    }
    else return;
}

template <typename T>
bool assertSorted(T *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}

int main() {

    printf("Array before being sorted : ");
    printArray(arr, size);

    mergeSort(0, size - 1);

    printf("After sorting : ");
    printArray(newArray, size);

    //Asserting array's been sorted
    if (assertSorted(newArray, size)) cout << "OK\n";
    else  cout << "KO\n";
    
    return 0;
}
