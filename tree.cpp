#include <iostream>
#include <math.h>

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

class binarySearchTree
{
public:
    Node *root;
    binarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
            return;
        }
        Node *temp = root;
        // temp = root;

        while (true)
        {
            if (value == temp->value)
            {
                return;
            }
            if (value < temp->value)
            {
                if (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = new Node(value);
                    return;
                }
            }
            else if (value > temp->value)
            {
                if (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = new Node(value);
                }
            }
        }
    }

    void inOrderPrint(Node *curNode)
    {
        if (curNode == nullptr)
        {
            return;
        }
        inOrderPrint(curNode->left);
        std::cout << curNode->value << std::endl;
        inOrderPrint(curNode->right);
    }

    bool findNode(int value, Node *curNode)
    {
        if (curNode == nullptr)
        {
            return false;
        }
        else if (value == curNode->value)
        {
            return true;
        }
        else if (value < curNode->value)
        {
            return findNode(value, curNode->left);
        }
        else
        {
            return findNode(value, curNode->right);
        }
    }

    int findMin(Node *curNode)
    {
        if (curNode == nullptr)
        {
            return -1;
        }
        while (curNode->left != nullptr)
        {
            curNode = curNode->left;
        }
        return curNode->value;
    }

    int findMax(Node *curNode)
    {
        if (curNode == nullptr)
        {
            return -1;
        }
        while (curNode->right != nullptr)
        {
            curNode = curNode->right;
        }
        return curNode->value;
    }
};

int main()
{
    binarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.inOrderPrint(tree.root);
    bool ifFound = tree.findNode(2, tree.root) == 1;
    int min = tree.findMin(tree.root);
    int max = tree.findMax(tree.root);

    std::cout << "Find node: " << ifFound << std::endl;
    std::cout << "Find max: " << max << std::endl;
    std::cout << "Find min: " << min << std::endl;

    return 0;
}