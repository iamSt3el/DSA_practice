#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;  // Lower precedence for other characters or invalid operators
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;
    
    for (char token : infix) {
        if (isalnum(token)) {  // Operand
            postfix += token;
        } else if (token == '(') {  // Left parenthesis
            operatorStack.push(token);
        } else if (token == ')') {  // Right parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();  // Pop the left parenthesis
        } else {  // Operator
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(token)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    
    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
