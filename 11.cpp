#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, key;
    int l, r, m;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    l = 0;
    r = n - 1;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (arr[m] == key)
        {
            cout << "Element found at position " << m + 1;
            return 0;
        }
        else if (arr[m] < key)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << "Element not found";

    return 0;
}