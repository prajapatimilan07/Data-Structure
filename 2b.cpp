#include <iostream>
using namespace std;

void callByValue(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    n--;
    callByValue(n);
}

void callByReference(int &n)
{
    if (n == 0)
        return;

    cout << n << " ";
    n--;
    callByReference(n);
}

int main()
{
    int value = 5;
    int reference = 5;

    cout << "Call by Value:" << endl;
    cout << "Before function call: " << value << endl;
    callByValue(value);
    cout << "\nAfter function call: " << value << endl;

    cout << "\n\nCall by Reference:" << endl;
    cout << "Before function call: " << reference << endl;
    callByReference(reference);
    cout << "\nAfter function call: " << reference << endl;

    return 0;
}