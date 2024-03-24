#include <iostream>
#include <math.h>
using namespace std;

int binarySearch(int *arr, int size);

int binarySearch(int *arr, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < 13) //you can replace the 13 with your integer
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class List
{
private:
    Node *root = nullptr;
    Node *temp = nullptr;
public:
    int insert(int value)
    {
        Node *newNode = new Node(value);
        if(root == nullptr)
        {
            root = newNode;
            temp = root;
        }
        while (true)
        {
            if(value < temp->value)
            {
                temp->left = newNode;
                return true;
            }else{
                temp->right = newNode;
                return true;
            }
        }
        return false;
    }

    /*void print()
    {
        temp = root;
        Node* valueLeft;
        Node* valueRight;
        cout << root->value << endl;

        while (temp->left == nullptr && temp->right == nullptr)
        {
            valueLeft =  temp->left;
            valueRight = temp->right;
        }
    }*/
};

int main()
{
    int arr[7] = {1, 2, 7, 8, 9, 10, 12};
    List one;
    //one.insert(arr);

    for (int i = 0; i < 7; i++)
    {
        one.insert(arr[i]);
    }
    

    return 0;
}