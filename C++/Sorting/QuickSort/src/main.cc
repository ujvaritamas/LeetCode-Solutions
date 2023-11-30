#include <iostream>

#include "Quicksort.hh"

int main() {
    std::cout << "Hello, World!" << std::endl;

    QuickSort a;

    int test[] = {1, 5, 9, 8, 7, 10};

    int size = static_cast<int>(sizeof(test)/sizeof(test[0]));

    a.printArray(test, size);

    QuickSort::quickSort(test, 0, size-1);

    a.printArray(test, size);

    a.display();

    return 0;
}