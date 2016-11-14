#include <iostream>

using namespace std;

int arr[9] = {6, 5, 1, 3, 8, 4, 7, 9, 2};
int size = 9;

template <typename T>
int indiceElem(const T elem, const T *array, const int &size){
	for(int i = 0; i < size; i++ ){
		if(elem == array[i]) return i;
	}

	// Element not found
	return -1;
}

template <typename T>
void printArray(const T *array, const int &size) {
    int i;
    for (i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << "\n";
}

int main() {

    printf("Array before being sorted : ");
    printArray(arr, size);

    int found = indiceElem(8 , arr, size);
    int notFound = indiceElem(10 , arr, size);

    // Asserting one element found
    if (found == 4) cout << "OK\n";
    else  cout << "KO\n";

    // Asserting one element not found
    if (notFound == -1) cout << "OK\n";
    else  cout << "KO\n";
    
    return 0;
}
