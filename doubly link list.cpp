#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *prev;
    Node *next;
};

Node *first = NULL, *last = NULL;

Node *create_node(int x)
{
    Node *temp = new Node;

    temp->info = x;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

void insert_first(int x)
{
    Node *temp;
    temp = create_node(x);

    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void insert_last(int x)
{
    Node *temp;
    temp = create_node(x);

    if (last == NULL)
    {
        first = last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void insert_pos(int pos, int x)
{
    Node *temp;
    temp = create_node(x);

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (pos == 1)
    {
        insert_first(x);
        delete temp;
        return;
    }

    int i = 1;
    Node *temp1 = first;

    while (i < pos - 1 && temp1->next != NULL)
    {
        temp1 = temp1->next;
        i++;
    }

    if (i != pos - 1)
    {
        cout << "Invalid position." << endl;
        delete temp;
        return;
    }

    Node *y = temp1->next;

    temp->next = y;
    temp->prev = temp1;

    temp1->next = temp;

    if (y != NULL)
    {
        y->prev = temp;
    }

    if (temp->next == NULL)
    {
        last = temp;
    }
}

void display()
{
    char ch;

    cout << "Enter F for Forward or L for Last: ";
    cin >> ch;

    Node *temp;

    if (ch == 'F' || ch == 'f')
    {
        temp = first;

        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
    }
    else if (ch == 'L' || ch == 'l')
    {
        temp = last;

        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->prev;
        }
    }
    else
    {
        cout << "Invalid choice.";
    }

    cout << endl;
}

int main()
{
    int choice, x, pos;

    while (1)
    {
        cout << "\n1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert Position" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insert_first(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            insert_last(x);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;

            cout << "Enter value: ";
            cin >> x;

            insert_pos(pos, x);
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }
}