#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int p(char s)
{
    if(s == '+' || s == '-')
    {
        return 1;
    } 
    else if(s == '*' || s == '/')
    {
        return 2;
    }
    return 0;
}


string convert(const string &infix)
{
    stack<char> op;
    string postfix;

    for (char token : infix)
    {
        if (isalnum(token))
        {
            postfix += token;
        }
        else if (token == '(')
        {
            op.push(token);
        }
        else if (token == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while (!op.empty() && p(op.top()) >= p(token))
            {
                postfix += op.top();
                op.pop();
            }
            op.push(token);
        }
    }
    while (!op.empty())
    {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

int main()
{
    string s;
    cout << "Enter a infix: " << endl;
    getline(cin, s);

    cout << convert(s); 

    return 0;
}