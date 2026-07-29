#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main() {
    stack<int> s;
    string exp;

    cout << "Enter postfix expression (space separated): ";
    getline(cin, exp);

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else {
            if (s.size() < 2) {
                cout << "Invalid Postfix Expression";
                return 0;
            }

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            switch (exp[i]) {
                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    if (b == 0) {
                        cout << "Division by zero";
                        return 0;
                    }
                    s.push(a / b);
                    break;

                default:
                    cout << "Invalid Operator";
                    return 0;
            }
        }
    }

    if (s.size() != 1) {
        cout << "Invalid Postfix Expression";
        return 0;
    }

    cout << "Result = " << s.top() << endl;

    return 0;
}