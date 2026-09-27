#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }
}

void deleteItem()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        cout << queue[front] << " deleted from queue." << endl;
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- Queue Menu -----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insert(value);
            break;

        case 2:
            deleteItem();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}