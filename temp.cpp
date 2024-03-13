#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class List
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    List(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void prepend(int value)
    {
        Node* newnode = new Node(value);
        if(length == 0){
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            Node* temp = newnode;
            head  = temp;
        }
        length++;
    }
};

int main()
{
    List temp(5);
    temp.append(6);
    temp.append(7);
    temp.prepend(4);
    temp.printList();
}