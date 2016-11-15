#include "../array.cpp"

using namespace std;

int main() {
    int a[8] = {6, 3, 9, 8, 1, 5, 4, 2};
    Array<int> array(a, 8);
    printf("Array before sorting : ");
    array.print();

    //Sorting the array of size 8
    array.doCountSort();

    printf("Array after being sorted : ");
    array.print();
    
    return 0;
}
