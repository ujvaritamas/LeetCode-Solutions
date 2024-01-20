#include <iostream>

#include "QuickSort.hh"

int main() {
    std::cout << "Hello, World!" << std::endl;

    int test[] = {1, 5, 9, 8, 7, 10};

    int size = static_cast<int>(sizeof(test)/sizeof(test[0]));

    QuickSort::printArray(test, size);

    QuickSort::quickSort(test, 0, size-1);

    QuickSort::printArray(test, size);

    return 0;
}