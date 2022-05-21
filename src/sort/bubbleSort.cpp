#include <iostream>

// function prints array elements
void printArr(int arr[], int size) {

    for(int i=0; i < size; i++) {

        std::cout << arr[i] << " ";

    }

    std::cout << "\n";
}

// swap two values of array
void swap(int &x, int &y) {

    int temp = x;
    x = y;
    y = temp;

}


void bubbleSort(int arr[], int size) {

    // loop all over the array
    for(int i=0; i < size; i++) {
        
        // loop over array x2 but (j < i) :D
        for(int j=0; j < size - 1; j++) {

            // check if frist elemnet > secound element
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]); // swap elements

        }

    }

}


int main() {

    /*
    
    * Bubble sort is an easiest sorting algorithm.
    * how Bubble sort works:
    *       1. loop all over the array
    * 
    *       2. inested loop with less rounds than main loop
    *          this for moving biggest number to last index
    *          and skipping last index.
    *       
    *       3. check if frist element greater than secound element
    *          if it true than we swap the elements

    */

    int lenArr = 5;
    int unsortedArr[lenArr] = {1, 3, 2, 4, 0};
    
    std::cout << "unsorted: ";
    printArr(unsortedArr, lenArr);

    bubbleSort(unsortedArr, lenArr);

    std::cout << "sorted: ";
    printArr(unsortedArr, lenArr);

    return 0;
}