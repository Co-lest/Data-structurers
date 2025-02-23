#include <iostream>

int linearSearch(int data[], int size, int input);

int main(void)
{
    int data[] = {5, 2, 9, 1, 5, 6};

    const int size = sizeof(data) / sizeof(int);
    int input;

    std::cout << "Enter the number being searched: " ;
    std::cin >> input;

    const int result = linearSearch(data, size, input);

    if (result == -1)
    {
        std::cout << "The number entered is not in the array!" << std::endl;
    }
    else 
    {
        std::cout << "Found the number in index: " << result << std::endl;
    }

    return 0;
}

int linearSearch(int data[], int size, int input) 
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == input)
        {
            std::cout << "Iterations: " << count++ << std::endl; 
            return i;
        }
        count++;
    }
    return -1;
} 