#include <iostream>

void binarySearch(const int arr[], int &result, int size, int input, int &count, bool &found);

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int arr2[] = {2, 3, 3, 6, 8, 12, 16, 23, 23, 26, 34, 38, 53, 56, 67, 72, 77, 91};

    int size = sizeof(arr) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    int input, result, count = 0;
    bool found = false;

    std::cout << "Enter the number being searched: ";
    std::cin >> input;

    binarySearch(arr, result, size, input, count, found);

    if (found)
    {
        std::cout << "Number is in the index: " << result << std::endl;
        std::cout << "Number of iterations in the loop: " << count << std::endl;
    }
    else
    {
        std::cout << "Number entered is not in the list!" << std::endl;
    }

    count = 0;
    found = false;

    binarySearch(arr2, result, size2, input, count, found);

    if (found)
    {
        std::cout << "Number is in the index: " << result << std::endl;
        std::cout << "Number of iterations in the loop: " << count << std::endl;
    }
    else
    {
        std::cout << "Number entered is not in the list!" << std::endl;
    }

    return 0;
}

void binarySearch(const int arr[], int &result, int size, int input, int &count, bool &found)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == input)
        {
            found = true;
            result = mid;
            return;
        }
        else if (arr[mid] < input)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        count++;
    }
    found = false;
}