#include <iostream>

int binarySearch(int arr[], int size, int input);

int main ()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int arr2[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 34, 53, 26, 23, 3, 67, 3, 6, 77, 91};

    int size = sizeof(arr) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    int input;

    std::cout << "Enter the number being searched: ";
    std::cin >> input;

    const int result = binarySearch(arr, size, input);

    if (result == -1)
    {
        std::cout << "Number entered is not in the list!" << std::endl;
    }
    else
    {
        std::cout << "Number is in the index: " << result << std::endl;
    }

    const int result2 = binarySearch(arr2, size2, input);

    if (result2 == -1)
    {
        std::cout << "Number entered is not in the list!" << std::endl;
    }
    else
    {
        std::cout << "Number is in the index: " << result << std::endl;
    }
    
    return 0;
}

int binarySearch(int arr[], int size, int input)
{
    int low = 0;
    int high = size - 1;
    int count = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == input)
        {
            std::cout << "Number of iterations in the loop: " << count++ << std::endl;
            return mid;
        }else if (arr[mid] < input) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        count++;
    }
    return -1;
}