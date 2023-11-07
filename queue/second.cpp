#include <iostream>
#include <queue>
using namespace std;


void add(queue<int> &q, int size)
{
    int n;
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> n;
        q.push(n);
    }
}
void print(queue<int> first)
{
    while(!first.empty())
    {
        cout << first.front() << endl;
        first.pop();
    }
}

int main()
{
    queue<int> first;
    int size;
    cout << "Enter the amount of the elements: " << endl;
    cin >> size;

    add(first, size);
    print(first);
    return 0;
}