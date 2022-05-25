#include <iostream>
#include <cmath>

struct SearchStats {

    int jumps = 0; // counting jumps
    int jumpSize = 0; // jump gap(size) sqrt(n)
    int linearSteps = 0; // counting linear back steps

};


int jumpSearch(int arr[], int size, int item, SearchStats &stats) {

    // calculate jump size
    stats.jumpSize = sqrt(size);
    int currIndex = 0;

    
    // loop with size of array
    while(currIndex <= size){

        // check if current element is equals to item
        if(arr[currIndex] == item) return currIndex;

        // check if current elemnt is greater than item
        // then we will subtract currIndex by 1 each loop
        // to back to previous index, and inceremnt stats.linearSteps by 1
        else if(arr[currIndex] > item) {
            currIndex--;
            stats.linearSteps++;
        }


        // otherwise we will increment currIndex by stats.jumpSize,
        // jumpSize value is sqrt(size) ex. sqrt(10) = 
        else{

            currIndex += stats.jumpSize;
            stats.jumps++;
        
        }

        
    }
    
    // item not found !
    std::cout << "The element you looking for is not there !\n\n";
    return -1;
 
}


int main(int argc, char *argv[]) {


    /*
    
    * Jump search is a searching algorithm (best than linear search).
    * basically, the algorithm jump a specific range called jump size or gap.
    * The algorithm only works on sorted arrays !
    * How jump search works:
    *    
    *    1. set jump size to sqrt(arrayLength).
    *    2. loop by the size of array
    *    3. check if array[currentIndex] eqauls searched item.
    *           then we will return the index.
    *
    *    4. check if array[currentArray] greater than item
    *           then we will subtract currentIndex by 1
    *           to continue linear search for previous index
    * 
    *    5. otherwise we will incerement current index by jump size for example 3.
    *       
    *    - when the function don't find the element it will return -1
    *    - if the currentIndex is greater than item, we will subtract it by 1 (previous index)
    
    */

    // initialize stats object
    SearchStats stats;

    int arr[] = {-15, 0, 3, 39, 40, 48, 49, 71, 83, 97};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    int elementIndex = jumpSearch(arr, arrlen, 71, stats);
    int element = arr[elementIndex];

    // when the jumpSearch() return -1
    // searchElemnet value will be randomize so we set it to -1 (element not found)
    (element > arr[arrlen] && elementIndex < 0) ? element = -1 : element;
    

    // output stats
    std::cout << "Index: " << elementIndex << std::endl;
    std::cout << "Element: " << element << std::endl;
    std::cout << "Jumps: " << stats.jumps << std::endl;
    std::cout << "Jump Size: " << stats.jumpSize << std::endl;
    std::cout << "Linear steps: " << stats.linearSteps << std::endl;

    return 0;
}