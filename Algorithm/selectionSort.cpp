#include <iostream>

void selectionSort(int *arr, int n);

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int length;
    std::cout << "Enter the number of elements: " << std::endl;
    std::cin >> length;
    
    int *arr = new int[length];

    std::cout << "Enter the elements: ";
    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
    }

    selectionSort(arr, length);

    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    
    delete[] arr;
    return 0;
}