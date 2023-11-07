#include <iostream>
using namespace std;

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

void create(Node *&head, Node *&tail, int d)
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
int main()
{
    int size;
    int data;
    cout << "Enter the size of the linked list: " << endl;
    cin >> size;

    Node *n1 = nullptr;
    Node *head = n1;
    Node *tail = n1;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: " << endl;
        cin >> data;
        addAtEnd(head, tail, data);
        cout << head -> data << endl;
    }

    print(head);
    return 0;
}
