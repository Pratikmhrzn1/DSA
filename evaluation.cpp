#include <iostream>
#include <stack>
#include <string>
using namespace std;
string intToString(int x) {
    string s = "";
    bool neg = false;

    if (x == 0)
        return "0";

    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        char digit = (x % 10) + '0';
        s = digit + s;
        x /= 10;
    }
    if (neg)
        s = "-" + s;
    return s;
}
int main() {
    string expr;
    cout<<"\nPratik Maharjan:\n";
    cout << "Enter expression (e.g. 123+*321-+*): ";
    cin >> expr;

    stack<int> s;

    cout << "\nScanned Char.    Result             Stack\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
            cout << "      " << c << "                          ";
        }
        else {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();

            int result;
            string operation;

            if (c == '+') {
                result = left + right;
                operation = intToString(left) + "+" +
                            intToString(right) + "=" +
                            intToString(result);
            }
            else if (c == '-') {
                result = left - right;
                operation = intToString(left) + "-" +
                            intToString(right) + "=" +
                            intToString(result);
            }
            else if (c == '*') {
                result = left * right;
                operation = intToString(left) + "*" +
                            intToString(right) + "=" +
                            intToString(result);
            }
            else {
                cout << "Unknown operator: " << c << endl;
                return 0;
            }

            s.push(result);
            cout << "      " << c << "          " << operation << "          ";
        }

        // Print stack
        stack<int> temp = s;
        bool first = true;
        while (!temp.empty()) {
            if (!first) cout << ",";
            cout << temp.top();
            temp.pop();
            first = false;
        }
        cout << endl;
    }
    cout << "\nFinal answer: " << s.top() << endl;
    return 0;
}

