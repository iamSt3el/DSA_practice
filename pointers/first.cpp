#include <iostream>
#include <stack>
using namespace std;

void add(stack<int>& s, int size)
{
    int num{};
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> num;
        s.push(num);
    }
}


void print(stack<int> s)
{


    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}


void reverse(stack<int> s)
{   
    stack<int> s2;

    while(!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
    
    print(s2);
}

int main()
{
    stack<int> first;


    int size{};
    cout << "Enter the number of the elements: " << endl;
    cin >> size;
    add(first, size);

    cout << "The elements of the stack" << endl;
    print(first);

    cout << "The elements of the stack in reverse order" << endl;
    reverse(first);

    return 0;
}