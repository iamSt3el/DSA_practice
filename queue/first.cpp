#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> name;

    name.push(1);
    name.push(2);
    name.push(3);
    name.push(4);

    cout << "Front: " << name.front() << endl;
    cout << "Back:  " << name.back() << endl;


    while(!name.empty())
    {
        cout << name.front() << endl;
        name.pop();
    }
    return 0;
}