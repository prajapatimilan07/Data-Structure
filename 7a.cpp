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

    if (first == NULL)
    {
        first = temp;
        temp->next = first;
        return;
    }

    Node *x = first->next;

    while (x->next != first)
    {
        x = x->next;
    }

    temp->next = first;
    x->next = temp;
    first = temp;
}

void insert_last(int value)
{
    Node *temp = new Node;
    temp->info = value;

    if (first == NULL)
    {
        first = temp;
        temp->next = first;
        return;
    }

    Node *x = first->next;
    Node *y = first;

    while (x != first)
    {
        y = x;
        x = x->next;
    }

    y->next = temp;
    temp->next = first;
}

void insert_pos(int given, int value)
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *x = first;

    while (x->info != given && x->next != first)
    {
        x = x->next;
    }

    if (x->info != given)
    {
        cout << "Given node not found." << endl;
        return;
    }

    Node *temp = new Node;
    temp->info = value;
    temp->next = x->next;
    x->next = temp;
}

void delete_first()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (first->next == first)
    {
        delete first;
        first = NULL;
        return;
    }

    Node *x = first->next;

    while (x->next != first)
    {
        x = x->next;
    }

    Node *temp = first;
    first = first->next;
    x->next = first;

    delete temp;
}

void delete_last()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (first->next == first)
    {
        delete first;
        first = NULL;
        return;
    }

    Node *x = first->next;
    Node *y = first;

    while (x->next != first)
    {
        y = x;
        x = x->next;
    }

    y->next = first;
    delete x;
}

void delete_pos(int given)
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *x = first;

    while (x->info != given && x->next != first)
    {
        x = x->next;
    }

    if (x->info != given)
    {
        cout << "Given node not found." << endl;
        return;
    }

    Node *temp = x->next;

    if (temp == first)
    {
        delete_first();
        return;
    }

    x->next = temp->next;
    delete temp;
}

void display()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *x = first;

    while (x->next != first)
    {
        cout << x->info << " -> ";
        x = x->next;
    }

    cout << x->info << " -> FIRST" << endl;
}

int main()
{
    int choice, value, given;

    while (1)
    {
        cout << "1. Insert First Node" << endl;
        cout << "2. Insert Last Node" << endl;
        cout << "3. Insert After Given Node" << endl;
        cout << "4. Delete First Node" << endl;
        cout << "5. Delete Last Node" << endl;
        cout << "6. Delete Node After Given Node" << endl;
        cout << "7. Display All Nodes" << endl;
        cout << "8. Exit" << endl;

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
            delete_first();
            break;

        case 5:
            delete_last();
            break;

        case 6:
            cout << "Enter given node value: ";
            cin >> given;
            delete_pos(given);
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Exit." << endl;
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }
}