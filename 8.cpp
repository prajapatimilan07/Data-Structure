#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
};

node* create_node(int x)
{
    node *temp;

    temp = new node;

    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void set_left(node *p, int x)
{
    p->left = create_node(x);
}

void set_right(node *p, int x)
{
    p->right = create_node(x);
}

void inorder(node *p)
{
    if(p != NULL)
    {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}

void preorder(node *p)
{
    if(p != NULL)
    {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
    }
}

int main()
{
    node *root, *p, *q;
    int x;
    char ch;

    root = NULL;

    while(1)
    {
        cout << "\nEnter value: ";
        cin >> x;

        if(root == NULL)
        {
            root = create_node(x);
        }
        else
        {
            p = root;

            while(p != NULL)
            {
                q = p;

                if(x >= p->info)
                    p = p->right;
                else
                    p = p->left;
            }

            if(x < q->info)
                set_left(q, x);
            else
                set_right(q, x);
        }

        cout << "Do you want to continue (y/n): ";
        cin >> ch;

        if(ch == 'n' || ch == 'N')
            break;
    }

    cout << "\n\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}