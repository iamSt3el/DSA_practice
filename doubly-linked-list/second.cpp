#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

int sizeOfList(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}
// Functiton to print the linked list throung head
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

// Function to print linked list through tail
void print2(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

// To add elemnt at front
void addAtFront(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = head;
        head->prev = nodeToInsert;
        head = nodeToInsert;
    }
    cout << "Added element at front successfully" << endl;
}
// To add element at end
void addAtEnd(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *nodeToInsert = new Node(data);
        tail->next = nodeToInsert;
        nodeToInsert->prev = tail;
        tail = nodeToInsert;
    }
    cout << "Added element at end successfully" << endl;
}

// function to add at any position
void addAtPosition(Node *&head, Node *&tail, int position, int data)
{

    if (position > (sizeOfList(head) + 1))
    {
        cout << "Position is out of bound" << endl;
        return;
    }
    else
    {
        if (position <= 1)
        {
            addAtFront(head, tail, data);
            return;
        }
        int count = 1;
        Node *temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            addAtEnd(head, tail, data);
            return;
        }

        Node *nodeToInsert = new Node(data);

        nodeToInsert->next = temp->next;
        nodeToInsert->prev = temp;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
    }
}

// funtion to delete at first
void deletAtStart(Node *&head, Node* &tail)
{
    if (head->next != NULL)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        delete (temp);
    }
    else
    {
        delete (head);
        head = NULL;
        tail = NULL;
    }
}

// funtion to delete at end

void deleteAtEnd(Node *&tail, Node *&head)
{
    if (tail->prev != NULL)
    {
        Node *temp = tail;
        temp->prev->next = NULL;
        tail = temp->prev;
        delete (temp);
    }
    else
    {
        delete(tail);
        tail = NULL;
        head = NULL;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int choice = 0;

    while (choice != 9)
    {
        cout << "---------------------------------" << endl;
        cout << "Press 1 to add data at front." << endl;
        cout << "Press 2 to print the linked list." << endl;
        cout << "Press 3 to print backward." << endl;
        cout << "Press 4 to add at end." << endl;
        cout << "Press 5 to add at any position." << endl;
        cout << "Press 6 to know the size of the linekd list." << endl;
        cout << "Press 7 to delete the starting node." << endl;
        cout << "Press 8 to delete at end." << endl;
        cout << "Press 9 to exit." << endl;
        cout << "---------------------------------" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        int data{};
        int position{};
        int size{};
        switch (choice)
        {
        case 1:
            cout << "Enter a data: ";
            cin >> data;
            addAtFront(head, tail, data);
            break;
        case 2:
            cout << "Linked list: ";
            print(head);
            break;
        case 3:
            cout << "Linked list data: ";
            print2(tail);

            break;
        case 4:
            cout << "Enter a data: ";
            cin >> data;
            addAtEnd(head, tail, data);
            break;

        case 5:
            cout << "Enter a position: ";
            cin >> position;
            cout << "Enter a data: ";
            cin >> data;
            addAtPosition(head, tail, position, data);
            cout << "Added successfully." << endl;
            break;
        case 6:
            size = sizeOfList(head);
            cout << "The size of the linked list is: " << size << endl;
            break;
        case 7:
            if (sizeOfList(head) != 0)
            {
                deletAtStart(head, tail);
                cout << "Deleted." << endl;
                break;
            }
            else
            {
                cout << "Linked list in empty" << endl;
                break;
            }
        case 8:
            if (sizeOfList(head) != 0)
            {
                deleteAtEnd(tail, head);
                cout << "Deleted." << endl;
                break;
            }
            else
            {
                cout << "Linked list in empty" << endl;
                break;
            }
        case 9:
            cout << "Thansks.";
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2 , 3 and 5to exit." << endl;
            break;
        }
    }

    // print2(tail);

    return 0;
}