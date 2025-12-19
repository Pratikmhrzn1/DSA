#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

stack<char> st;

void push(char c) {
    st.push(c);
}

char pop() {
    char x = st.top();
    st.pop();
    return x;
}

string stackToString() {
    stack<char> temp = st;
    string s = "";
    while (!temp.empty()) {
        s = temp.top() + s;
        temp.pop();
    }
    return s;
}

int prec(char c) {
    if (c == '$') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isRightAssociative(char c) {
    return (c == '$');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}

// INFIX TO POSTFIX
string infixToPostfix(string exp) {
    while (!st.empty()) st.pop();
    string output = "";
    cout << "\nScan | Postfix | Stack\n";
    cout << "----------------------\n";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isOperand(c)) {
            output += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(')
                output += pop();
            st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                  (prec(c) < prec(st.top()) ||
                  (prec(c) == prec(st.top()) && !isRightAssociative(c)))) {
                output += pop();
            }
            push(c);
        }

        cout << "  " << c << "  |  " << output << "  |  "
             << stackToString() << endl;
    }

    while (!st.empty()) {
        output += pop();
        cout << "     |  " << output << "  |  "
             << stackToString() << endl;
    }

    return output;
}

// INFIX TO PREFIX
string infixToPrefix(string exp) {
    reverse(exp.begin(), exp.end());

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }

    string post = infixToPostfix(exp);
    reverse(post.begin(), post.end());
    return post;
}

// MAIN
int main() {
    int choice;
    string exp;

    cout << "1 -> Postfix\n2 -> Prefix\nChoice: ";
    cin >> choice;

    cout << "Enter infix expression: ";
    cin >> exp;

    if (choice == 1)
        cout << "\nFinal Postfix = " << infixToPostfix(exp);
    else if (choice == 2)
        cout << "\nFinal Prefix = " << infixToPrefix(exp);
    else
        cout << "Invalid choice";

    return 0;
}
