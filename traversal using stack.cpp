#include <iostream>
using namespace std;

#define MAX 100

struct node
{
    int info;
    node *left;
    node *right;
};

node* stack[MAX];
int top = -1;

void push(node *p)
{
    stack[++top] = p;
}

node* pop()
{
    return stack[top--];
}

bool empty()
{
    return top == -1;
}

node* create_node(int x)
{
    node *temp = new node;

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

void inorder(node *root)
{
    node *p = root;

    while(p != NULL || !empty())
    {
        while(p != NULL)
        {
            push(p);
            p = p->left;
        }

        p = pop();
        cout << p->info << " ";
        p = p->right;
    }
}

void preorder(node *root)
{
    if(root == NULL)
        return;

    push(root);

    while(!empty())
    {
        node *p = pop();

        cout << p->info << " ";

        if(p->right != NULL)
            push(p->right);

        if(p->left != NULL)
            push(p->left);
    }
}

void postorder(node *root)
{
    if(root == NULL)
        return;

    node *p = root;
    node *last = NULL;

    while(p != NULL || !empty())
    {
        while(p != NULL)
        {
            push(p);
            p = p->left;
        }

        p = stack[top];

        if(p->right != NULL && last != p->right)
        {
            p = p->right;
        }
        else
        {
            cout << p->info << " ";
            last = p;
            pop();
            p = NULL;
        }
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

    top = -1;

    cout << "\n\nInorder Traversal: ";
    inorder(root);

    top = -1;

    cout << "\nPreorder Traversal: ";
    preorder(root);

    top = -1;

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}