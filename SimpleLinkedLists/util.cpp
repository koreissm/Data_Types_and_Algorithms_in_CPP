#include "util.h"

using namespace std;

void clear(void) {
    cout << "\033[2J";
    cout << "\033[" << 0 << ";" << 0 << "H";
}

void displayMenu() {
    cout << "Choices : ";
}
