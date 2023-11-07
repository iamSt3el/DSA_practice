#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

// to print the elements of the linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// to get the length of the linked list
int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// fucntion to add element at the start of the linked list
void addAtStart(Node *&head, Node *&tail, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// function to add element at the end of the linked list
void addAtEnd(Node* &head, Node *&tail, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// insert at any position in the linked list

// insert at any position in the linked list
void atAnyPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position <= 1)
    {
        addAtStart(head, tail, d);
        return;
    }
    int count = 1;
    Node *temp = head;

    while (count < position - 1 && temp)
    {
        temp = temp->next;
        count++;
    }

    if (temp)
    {
        Node *toInsert = new Node(d);
        toInsert->next = temp->next;
        toInsert->prev = temp;
        if (temp->next)
        {
            temp->next->prev = toInsert;
        }
        temp->next = toInsert;

        if (!toInsert->next) // Update the tail if necessary
        {
            tail = toInsert;
        }
    }
    else
    {
        cerr << "Position is out of bounds." << endl;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    addAtStart(head, tail, 10);
    addAtStart(head, tail, 9);

    addAtEnd(head, tail, 12);

    atAnyPosition(head, tail, 4, 34);

    print(head);

    cout << getLength(head);
    ;

    return 0;
}