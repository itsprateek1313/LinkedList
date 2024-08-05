#include <bits/stdc++.h>
using namespace std;

class Node
{ // Custom data type
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList
{ // Custom Data Structure
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            cout << "Please provide a valid index" << endl;
        }
        else if (index == 0)
        {
            insertAtHead(value);
        }
        else if (index == size)
        {
            insertAtEnd(value);
        }
        else
        {
            Node *t = new Node(value);
            Node *temp = head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int getElementByIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Please provide a valid index" << endl;
            return -1; // Return an invalid value to indicate error
        }

        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }

    void deleteAtHead()
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;

        if (size == 0)
        {
            tail = NULL;
        }
    }

    void deleteAtTail()
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        size--;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Please provide a valid index" << endl;
            return;
        }
        else if (index == 0)
        {
            deleteAtHead();
        }
        else if (index == size - 1)
        {
            deleteAtTail();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            size--;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(5);
    ll.display();
    ll.insert(2, 8);
    ll.display();

    ll.deleteAtHead();
    ll.display();

    ll.deleteAtTail();
    ll.display();

    ll.insertAtEnd(65);
    ll.insertAtEnd(43);
    ll.insertAtEnd(32);
    ll.insertAtEnd(12);
    ll.display();

    cout << ll.size << endl;

    ll.deleteAtIndex(4);
    ll.display();

    return 0;
}
