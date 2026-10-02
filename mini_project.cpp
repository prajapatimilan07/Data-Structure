
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    string phone;
    string email;
    string address;
    Node *next;
};

Node *first = NULL;

void insert_first()
{
    Node *temp = new Node;

    cout << "Enter name: ";
    getline(cin >> ws, temp->name);

    cout << "Enter phone number: ";
    getline(cin, temp->phone);

    cout << "Enter email: ";
    getline(cin, temp->email);

    cout << "Enter address: ";
    getline(cin, temp->address);

    temp->next = first;
    first = temp;

    cout << "Contact inserted successfully." << endl;
}

void insert_last()
{
    Node *temp = new Node;

    cout << "Enter name: ";
    getline(cin >> ws, temp->name);

    cout << "Enter phone number: ";
    getline(cin, temp->phone);

    cout << "Enter email: ";
    getline(cin, temp->email);

    cout << "Enter address: ";
    getline(cin, temp->address);

    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
        cout << "Contact inserted successfully." << endl;
        return;
    }

    Node *x = first;

    while (x->next != NULL)
    {
        x = x->next;
    }

    x->next = temp;

    cout << "Contact inserted successfully." << endl;
}

void insert_position()
{
    int pos;

    cout << "Enter position to insert contact: ";
    if (!(cin >> pos))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid position." << endl;
        return;
    }

    if (pos < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    Node *temp = new Node;

    cout << "Enter name: ";
    getline(cin >> ws, temp->name);

    cout << "Enter phone number: ";
    getline(cin, temp->phone);

    cout << "Enter email: ";
    getline(cin, temp->email);

    cout << "Enter address: ";
    getline(cin, temp->address);

    if (pos == 1)
    {
        temp->next = first;
        first = temp;
        cout << "Contact inserted successfully." << endl;
        return;
    }

    Node *x = first;

    for (int i = 1; i < pos - 1 && x != NULL; i++)
    {
        x = x->next;
    }

    if (x == NULL)
    {
        delete temp;
        cout << "Invalid position." << endl;
        return;
    }

    temp->next = x->next;
    x->next = temp;

    cout << "Contact inserted successfully." << endl;
}

void search_contact()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    string phone;

    cout << "Enter phone number to search: ";
    getline(cin >> ws, phone);

    Node *x = first;

    while (x != NULL && x->phone != phone)
    {
        x = x->next;
    }

    if (x == NULL)
    {
        cout << "Contact not found." << endl;
        return;
    }

    cout << "\nContact Found" << endl;
    cout << "Name: " << x->name << endl;
    cout << "Phone: " << x->phone << endl;
    cout << "Email: " << x->email << endl;
    cout << "Address: " << x->address << endl;
}

void update_contact()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    string phone;

    cout << "Enter phone number of contact to update: ";
    getline(cin >> ws, phone);

    Node *x = first;

    while (x != NULL && x->phone != phone)
    {
        x = x->next;
    }

    if (x == NULL)
    {
        cout << "Contact not found." << endl;
        return;
    }

    cout << "Enter new name: ";
    getline(cin >> ws, x->name);

    cout << "Enter new phone number: ";
    getline(cin, x->phone);

    cout << "Enter new email: ";
    getline(cin, x->email);

    cout << "Enter new address: ";
    getline(cin, x->address);

    cout << "Contact updated successfully." << endl;
}

void delete_first()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    Node *temp = first;
    first = first->next;
    delete temp;

    cout << "First contact deleted successfully." << endl;
}

void delete_last()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    if (first->next == NULL)
    {
        delete first;
        first = NULL;
        cout << "Last contact deleted successfully." << endl;
        return;
    }

    Node *x = first;

    while (x->next->next != NULL)
    {
        x = x->next;
    }

    Node *temp = x->next;
    x->next = NULL;
    delete temp;

    cout << "Last contact deleted successfully." << endl;
}

void delete_contact()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    string phone;

    cout << "Enter phone number to delete: ";
    getline(cin >> ws, phone);

    if (first->phone == phone)
    {
        Node *temp = first;
        first = first->next;
        delete temp;

        cout << "Contact deleted successfully." << endl;
        return;
    }

    Node *x = first;

    while (x->next != NULL && x->next->phone != phone)
    {
        x = x->next;
    }

    if (x->next == NULL)
    {
        cout << "Contact not found." << endl;
        return;
    }

    Node *temp = x->next;
    x->next = temp->next;
    delete temp;

    cout << "Contact deleted successfully." << endl;
}

void display()
{
    if (first == NULL)
    {
        cout << "Contact list is empty." << endl;
        return;
    }

    Node *x = first;
    int count = 1;

    while (x != NULL)
    {
        cout << "\nContact " << count << endl;
        cout << "Name: " << x->name << endl;
        cout << "Phone: " << x->phone << endl;
        cout << "Email: " << x->email << endl;
        cout << "Address: " << x->address << endl;

        x = x->next;
        count++;
    }
}

void free_list()
{
    while (first != NULL)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Insert Contact at First" << endl;
        cout << "2. Insert Contact at Last" << endl;
        cout << "3. Insert Contact at Any Position" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. Update Contact" << endl;
        cout << "6. Delete First Contact" << endl;
        cout << "7. Delete Last Contact" << endl;
        cout << "8. Delete Contact by Phone Number" << endl;
        cout << "9. Display All Contacts" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            insert_first();
            break;

        case 2:
            insert_last();
            break;

        case 3:
            insert_position();
            break;

        case 4:
            search_contact();
            break;

        case 5:
            update_contact();
            break;

        case 6:
            delete_first();
            break;

        case 7:
            delete_last();
            break;

        case 8:
            delete_contact();
            break;

        case 9:
            display();
            break;

        case 10:
            free_list();
            cout << "Program exited successfully." << endl;
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }
}