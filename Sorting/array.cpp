#include <iostream>

#define MIN 1000000000

using namespace std;

template <class T> class Array {

    private:
        T *_arr;
        T *_newArray;
        const int _size;

    public:
        Array(T *a, int size) : _size(size) {
            _arr = a;
            _newArray = new T[size];
        }

        void print() {
            int i;
            for (i = 0; i < _size; i++) 
                cout << _arr[i] << " ";
            cout << "\n";
        }

        //Swapping two values
        void swap(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        //Test if the array is sorted
        bool assertSorted() {
            int i;
            for (i = 0; i < _size; i++) {
                if (_arr[i] > _arr[i+1]) return false;
            }
            return true;
        }

        /**
         * B U B B L E   S O R T
         */
        void doBubbleSort() {
            int i;
            bool swapped = true;

            //Performing the algo while a swap has been done
            while (swapped) {
                swapped = false;
                for (i = 0; i < _size; i++) {
                    if (_arr[i] > _arr[i + 1] && i < _size - 1) {
                        swap(_arr[i], _arr[i + 1]);
                        swapped = true;
                    }
                }
            }
        }

        /**
         * M E R G E   S O R T
         */
        void merge(int lo, int mid, int hi) {
        int i = lo, j = mid + 1, k = lo;
        
        while (i <= mid && j <= hi) {
            if (_arr[i] < _arr[j]) {
                _newArray[k++] = _arr[i++];
            }
            else {
                _newArray[k++] = _arr[j++];
            }
        }

        //If array1 bigger than array2
        while (i <= mid) {
            _newArray[k++] = _arr[i++];
        }
        //If array2 bigger than array1
        while (j <= hi) {
            _newArray[k++] = _arr[j++];
        }

        //Updating the old array
        for (i = lo; i <= hi; i++)
            _arr[i] = _newArray[i];

        }

        void mergeSort(int lo, int hi) {
            if (lo == hi) return;
            
            int middle = (hi + lo) / 2;

            mergeSort(lo, middle);
            mergeSort(middle + 1, hi);

            merge(lo, middle, hi);    
        }

        void doMergeSort() {
            mergeSort(0, _size - 1);
            _arr = _newArray;
        }

        /**
         * I N S E R T I O N    S O R T 
         */
        void doInsertionSort() {
            int i, j;
            for (i = 0; i < _size; i++) {
                int tmp = _arr[i];
                j = i - 1;

                while (j >= 0 && _arr[j] > tmp) {
                    _arr[j + 1] = _arr[j];
                    j--;
                }
                _arr[j + 1] = tmp;
            }
        }

        /**
         * Q U I C K   S O R T
         **/
        int partition(int low, int high) {
            T pivot = _arr[high];
            int wall = low;
            int current = low;

            for (current = low; current <= high; current++) {
                if (_arr[current] < pivot) {
                    swap(_arr[current], _arr[wall]);
                    wall++;
                }
            }
            swap(_arr[wall], _arr[high]);

            return wall;
        }

        void quickSort(int low, int high) {
            if (low > high) return;
            int p = partition(low, high);

            quickSort(low, p-1);
            quickSort(p+1, high);

            return;
        }

        void doQuickSort() {
            quickSort(0, _size - 1);
        }

        /**
         * S E L E C T I O N   S O R T
         **/
        void doSelectionSort() {
            int i, j;
            for (i = 0; i < _size; i++) {
                //Searching for the min in the right of the array
                int min = MIN;
                int index = -1;
                for (j = i; j < _size; j++) {
                    if (_arr[j] < min) {
                        min = _arr[j];
                        index = j;
                    }
                }

                //Swapping
                swap(_arr[i], _arr[index]);
            }
        }
};
