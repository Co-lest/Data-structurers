#include <iostream>

void linearSearch(const int data[], int size, int input, int& result, int& iterations, bool& found);

int main(void)
{
    int data[] = {5, 2, 9, 1, 5, 6};
    int data2[] = {5, 2, 9, 7, 45, 34, 75, 45, 86, 75, 45, 38, 45, 6};

    const int size = sizeof(data) / sizeof(int);
    const int size2 = sizeof(data2) / sizeof(int);
    int input;

    std::cout << "Enter the number being searched: ";
    std::cin >> input;

    int result, iterations;
    bool found = false;
    linearSearch(data, size, input, result, iterations, found);

    if (found)
    {
        std::cout << "Found the number in index: " << result << std::endl;
        std::cout << "Iterations: " << iterations << std::endl;
    }
    else
    {
        std::cout << "The number entered is not in the array!" << std::endl;
    }

    linearSearch(data2, size2, input, result, iterations, found);

    if (found)
    {
        std::cout << "Found the number in index: " << result << std::endl;
        std::cout << "Iterations: " << iterations << std::endl;
    }
    else
    {
        std::cout << "The number entered is not in the array!" << std::endl;
    }

    return 0;
}

void linearSearch(const int data[], int size, int input, int& result, int& iterations, bool& found)
{
    iterations = 0;
    for (int i = 0; i < size; i++)
    {
        iterations++;
        if (data[i] == input)
        {
            result = i;
            found = true;
            return;
        }
    }
}