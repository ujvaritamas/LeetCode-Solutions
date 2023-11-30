#ifndef GUICKSORT_H_NAME
#define GUICKSORT_H_NAME

class QuickSort{
    public:
        // function to rearrange array (find the partition point)
        static int partition(int array[], int low, int high);
        void display();

        void printArray(int array[], int size);
        static void quickSort(int array[], int low, int high);
};

#endif