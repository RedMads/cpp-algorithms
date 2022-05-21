#include <iostream>


int binarySearch(int arr[], int size, int item) {

    // initialize low and high values
    int low = 0;
    int high = size - 1;

    // start search
    while(low <= high) {
        
        // get mid of array
        int mid = (low + high) / 2;

        // check if the mid index is the item
        if(arr[mid] == item)
            return mid;

        // check if middle element less than item
        // we will skip the half of array (from low)
        else if(arr[mid] < item)
            low = mid + 1;

        // skipping half of array (from high)
        else
            high = mid - 1;

    }

    // item not found
    return -1;

}


int main() {

    /*
    
    * In Binary seach algorithm array must be sorted
    * Binary search is fastest than linear seach (normal search)
    * Index -1 means algorithm doesn't find the element
    
    */
    
    int arrLen = 5;
    int array[arrLen] = {-100, 2, 54, 84, 1000};
    int target = -100;

    int searchedIndex = binarySearch(array, arrLen, target);
    int searchedElement = array[searchedIndex];

    // when the binarySearch() return -1
    // searchElemnet value will be randomize so we set it to -1 (element not found)
    (searchedElement > array[arrLen] && searchedIndex < 0) ? searchedElement = -1 : searchedElement;
    
    std::cout << "Index: " << searchedIndex << std::endl;
    std::cout << "Element: " << searchedElement << std::endl;

    return 0;
}