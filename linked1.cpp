#include <iostream>

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
    int length = 0;

public:
    Node *temp;
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (length != 0)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            tail = newNode;
            head = newNode;
        }
        length++;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        temp = head;
        newNode->next = head;
        head = newNode;
    }

    void deleting(int value)
    {
        Node *prev;
        temp = head;
        if (head->value == value)
        {
            // prev = head;
            head = temp->next;
        }
        else
        {
            while (temp->next != nullptr)
            {
                prev = temp;
                temp = temp->next;
                if (temp->value == value)
                {
                    prev->next = temp->next;
                    return;
                }
            }
            if (temp->value == value)
            {
                prev->next = nullptr;
                prev = tail;
                return;
            }
            else
            {
                std::cout << "There is no such value in the nodes! Please enter another node." << std::endl;
                return;
            }
        }
    }

    void printing()
    {
        Node *temPrint;
        temPrint = head;
        try
        {
            if (length == 0)
            {
                throw(length);
            }
            else
            {
                do
                {

                    std::cout << temPrint->value << "->";
                    temPrint = temPrint->next;

                } while (temPrint->next != nullptr);
                std::cout << temPrint->value;
            }
        }
        catch (int error)
        {
            std::cerr << "There is no node at the list: " << error << '\n';
        }
    }
};

int main()
{
    List one;
    one.append(6);
    one.append(7);
    one.prepend(2);
    one.prepend(1);
    one.deleting(7);
    one.printing();
    return 0;
}