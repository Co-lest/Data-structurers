#include <iostream>

int binarySearch(int arr[], int size, int target);

int main(void) {
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int targetValue;

    std::cout << "Enter the target value to search for: ";
    std::cin >> targetValue;

    int result = binarySearch(sortedArray, size, targetValue);

    if (result != -1) {
        std::cout << "Target value found at index: " << result << std::endl;
    } else {
        std::cout << "Target value not found in the array." << std::endl;
    }

    return 0;
}

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int count = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            std::cout << "Number of iterations in the loop: " << count++ << std::endl;
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;  
        } else {
            high = mid - 1;
        }
        count++; //number of iterations in the loop
    }

    return -1;
}