#include <iostream>

using namespace std;

int arr[9] = {1, 3, 5, 6, 9, 15, 16, 20, 25};
//int arr[9] = {6, 5, 1, 3, 8, 4, 7, 9, 2};
int size = 9;


//This function assumes that the given array is sorted
template <typename T>
int binarySearch(const T element, const T *array, const int &begin, const int &end){
    int i;
    int middle = (begin + end) / 2;
    if (begin > end) return -1; //Element not in array

    if (element == array[middle]) return middle; //Found
    else if (element > array[middle])
        return binarySearch(element, array, middle + 1, end); //Search in the right subarray
    else
        return binarySearch(element, array, begin, middle - 1); //Search in the left subarray

}

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

int main() {

    printf("Array : ");
    printArray(arr, size);

    int found = binarySearch(15 , arr, 0, size - 1);

    cout << "found : " << found << endl;

    // Asserting one element found
    if (found == 5) cout << "OK\n";
    else  cout << "KO\n";

    
    return 0;
}
