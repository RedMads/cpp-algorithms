#include <iostream>


int linearSearch(int arr[], int size, int item) {

    // loop all over the array
    for(int i=0; i<size; i++) {

        // check every index until we find the element
        if(arr[i] == item) return i;

    }

    std::cout << "The element you looking for is not there !\n";
    return -1;
}


int main() {


    /*
    
    * Linear search (normal search) is slow specially with large arrays
    * How linear search works:
    *   1. loop over the array
    *   2. incerment i by one each loop (index increment)
    *   3. check if element equals to item at array[i] 
    
    * Linear search is like a brute-force is useless with large arrays
    * I don't recommend it at all !
    
    */

    int arr[] = {1, 49, 12, 84};
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    int elementIndex = linearSearch(arr, arrLen, 12);
    int element = arr[elementIndex];

    // when the linearSearch() return -1
    // searchElemnet value will be randomize so we set it to -1 (element not found)
    (element > arr[sizeof(arr) / sizeof(arr[0])] && elementIndex < 0) ? element = -1 : element;
    

    std::cout << "Index: " << elementIndex << std::endl;
    std::cout << "Element: " << element << std::endl;
    return 0;
}