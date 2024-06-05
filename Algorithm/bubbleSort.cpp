#include<iostream>

bool swap(int *arr, int length);

int main(void)
{
    int length;
    std::cout << "Enter the number of elements: ";
    std::cin >> length;
    
    int *arr = new int[length];

    std::cout << "Enter the elements: " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
    }
    
    while (swap(arr, length));
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}

bool swap(int *arr, int length)
{
    bool swapped = false;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swapped = true;
        }
    }
    return swapped;
}