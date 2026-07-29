#include <iostream>
using namespace std;

int main()
{
    int stack[5], top = -1;
    int choice, value;

    while (1)
    {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Push
            if (top == 4)
                cout << "Stack is full";
            else
            {
                cout << "Enter value: ";
                cin >> value;
                stack[++top] = value;
            }
            break;

        case 2: // Pop
            if (top == -1)
                cout << "Stack is empty";
            else
                cout << "Deleted: " << stack[top--];
            break;

        case 3: // Peek
            if (top == -1)
                cout << "Stack is Empty";
            else
                cout << "Top: " << stack[top];
            break;

        case 4: // Display
            if (top == -1)
                cout << "Stack is Empty";
            else
                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid Choice";
        }
    }
}