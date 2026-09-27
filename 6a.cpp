#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *first = NULL;

void insert_first(int value)
{
    Node *temp = new Node;
    temp->info = value;
    temp->next = first;
    first = temp;
}

void insert_last(int value)
{
    Node *temp = new Node;
    temp->info = value;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
        return;
    }

    Node *x = first;

    while (x->next != NULL)
    {
        x = x->next;
    }

    x->next = temp;
}

void insert_pos(int given, int value)
{
    Node *x = first;

    while (x != NULL && x->info != given)
    {
        x = x->next;
    }

    if (x == NULL)
    {
        cout << "Given node not found." << endl;
        return;
    }

    Node *temp = new Node;
    temp->info = value;
    temp->next = x->next;
    x->next = temp;
}

void display()
{
    Node *x = first;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    while (x != NULL)
    {
        cout << x->info << " -> ";
        x = x->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int choice, value, given;

    while (1)
    {
        cout << "\n1. Insert at First" << endl;
        cout << "2. Insert at Last" << endl;
        cout << "3. Insert Any Position" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insert_first(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insert_last(value);
            break;

        case 3:
            cout << "Enter given node value: ";
            cin >> given;

            cout << "Enter value to insert: ";
            cin >> value;

            insert_pos(given, value);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exit." << endl;
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
