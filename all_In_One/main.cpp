#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Array
{
public:
    int choice{};
    int size;
    vector<int> arr;
    void arrayFunc()
    {
        cout << "--------------------------------------------" << endl;
        cout << "| 1: For taking a array.                   |" << endl;
        cout << "| 2: For printing the array.               |" << endl;
        cout << "| 3: For finding the mim and max.          |" << endl;
        cout << "| 4: For finding the sum.                  |" << endl;
        cout << "| 5: For reversing the array.              |" << endl;
        cout << "| 6: For sorting the array.                |" << endl;
        cout << "| 7: For exit                              |" << endl;
        cout << "--------------------------------------------" << endl;

        cout << "Enter the actions for array: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter size of the array: " << endl;
            cin >> size;
            arr.resize(size);
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }
        }
        else if (choice == 2)
        {
            if (arr.size() == 0)
            {
                cout << "Please create a array first." << endl;
            }
            else
            {
                print();
            }
        }
        else if (choice == 3)
        {
            if (arr.size() == 0)
            {
                cout << "Please create a array first." << endl;
            }
            else
            {
                minAndMax(arr);
            }
        }
        else if (choice == 4)
        {
            if (arr.size() == 0)
            {
                cout << "Please create a array first." << endl;
            }
            else
            {
                sum();
            }
        }
        else if (choice == 5)
        {
            if (arr.size() == 0)
            {
                cout << "Please create a array first." << endl;
            }
            else
            {
                reverse();
            }
        }
        else if (choice == 6)
        {
            if (arr.size() == 0)
            {
                cout << "Please create a array first." << endl;
            }
            else
            {
                sort();
            }
        }
        else if (choice == 7)
        {
            return;
        }

        else
        {
            cout << "Enter a valid number." << endl;
        }
        arrayFunc();
    }

    void print()
    {
        cout << "Elements of the array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void minAndMax(vector<int> arr)
    {
        int min = arr[0];
        int max = arr[0];

        for (long long unsigned int i = 0; i < arr.size(); i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }

            if (max < arr[i])
            {
                max = arr[i];
            }
        }

        cout << "The maximum element in the given array is: " << max << endl;
        cout << "The minimum element in the given array is: " << min << endl;
    }

    void sum()
    {
        int sum{};
        for (long long unsigned int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        cout << "Total sum of the elements in the array: " << sum << endl;
    }

    void reverse()
    {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        print();
    }

    void sort()
    {
        for (long long unsigned int i = 0; i < arr.size(); i++)
        {
            for (long long unsigned int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }

        print();
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

class linkedList
{
public:
    int choice;
    int size;
    int data;
    Node *n1 = nullptr;
    Node *head = n1;
    Node *tail = n1;

    void linkedListFunc()
    {
        cout << "--------------------------------------------" << endl;
        cout << "| 1: For taking a Linked list.              |" << endl;
        cout << "| 2: For printing the linked list.          |" << endl;
        cout << "| 3: For exit.                              |" << endl;
        cout << "--------------------------------------------" << endl;

        cout << "Enter the actions for linked List: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (head != nullptr)
            {
                cout << "A linked list is already present." << endl;
            }
            else
            {
                cout << "Enter the size of liked list: " << endl;
                cin >> size;
                createLinkedList();
            }
        }
        else if (choice == 2)
        {
            print(head);
        }
        else if (choice == 3)
        {
            return;
        }

        else
        {
            cout << "Enter a valid number." << endl;
        }

        linkedListFunc();
    }

    void createLinkedList()
    {
        int subChoice{};
        cout << "--------------------------------------------" << endl;
        cout << "| 1: Adding at front.                       |" << endl;
        cout << "| 2: Adding at end.                         |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter you choice: " << endl;
        cin >> subChoice;
        if (subChoice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the element: " << endl;
                cin >> data;
                addAtFront(head, tail, data);
            }
        }
        else if (subChoice == 2)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the element: " << endl;
                cin >> data;
                addAtEnd(head, tail, data);
            }
        }

        else
        {
            cout << "Enter a valid number." << endl;
        }
    }

    void addAtFront(Node *&head, Node *&tail, int d)
    {
        Node *temp = new Node(d);
        if (head == nullptr)
        {
            head = tail = temp;
        }

        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void addAtEnd(Node *&head, Node *&tail, int d)
    {

        Node *temp = new Node(d);
        if (tail == nullptr)
        {
            tail = head = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class DoubleNode
{
public:
    int data;
    DoubleNode *next;
    DoubleNode *prev;

    DoubleNode(int d)
    {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoubleLinkedList
{
public:
    int choice;
    int size;
    int data;
    DoubleNode *n1 = nullptr;
    DoubleNode *head = n1;
    DoubleNode *tail = n1;

    void DoublelinkedListFunc()
    {
        cout << "--------------------------------------------" << endl;
        cout << "| 1: For taking a Double Linked list.       |" << endl;
        cout << "| 2: For printing the Double linked list.   |" << endl;
        cout << "| 3: For exit.                              |" << endl;
        cout << "--------------------------------------------" << endl;

        cout << "Enter the actions for linked List: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (head != nullptr)
            {
                cout << "A linked list is already present." << endl;
            }
            else
            {
                cout << "Enter the size of liked list: " << endl;
                cin >> size;
                createDoubleLinkedList();
            }
        }
        else if (choice == 2)
        {
            print(head);
        }
        else if (choice == 3)
        {
            return;
        }

        else
        {
            cout << "Enter a valid number." << endl;
        }

        DoublelinkedListFunc();
    }

    void createDoubleLinkedList()
    {
        int subChoice{};
        cout << "--------------------------------------------" << endl;
        cout << "| 1: Adding at front.                       |" << endl;
        cout << "| 2: Adding at end.                         |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter you choice: " << endl;
        cin >> subChoice;
        if (subChoice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the element: " << endl;
                cin >> data;
                addAtFront(head, tail, data);
            }
        }
        else if (subChoice == 2)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the element: " << endl;
                cin >> data;
                addAtEnd(head, tail, data);
            }
        }

        else
        {
            cout << "Enter a valid number." << endl;
        }
    }

    void addAtFront(DoubleNode *&head, DoubleNode *&tail, int d)
    {
        DoubleNode *temp = new DoubleNode(d);

        if (head == nullptr)
        {
            head = tail = temp;
        }

        else
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
    }
    void addAtEnd(DoubleNode *&head, DoubleNode *&tail, int d)
    {
        DoubleNode *temp = new DoubleNode(d);
        if (tail == nullptr)
        {
            tail = head = temp;
        }

        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void print(DoubleNode *head)
    {
        DoubleNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int choice{};
    string subChoice;

    while (choice != 4)
    {
        cout << "-------------------------------------" << endl;
        cout << "| 1: For Array actions              |" << endl;
        cout << "| 2: For linked list actions        |" << endl;
        cout << "| 3: For Double linked list actions |" << endl;
        cout << "| 4: For exit                       |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter you choice" << endl;
        cin >> choice;

        if (choice == 1)
        {
            Array arr;
            arr.arrayFunc();
        }

        else if (choice == 2)
        {
            linkedList ll;
            ll.linkedListFunc();
        }
        else if (choice == 3)
        {
            DoubleLinkedList dbl;
            dbl.DoublelinkedListFunc();
        }
        else
        {
            cout << "Enter a valid number." << endl;
        }
    }

    return 0;
}