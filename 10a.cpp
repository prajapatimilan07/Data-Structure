
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before bubble sort:\narr = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr.data(), n);

    cout << "\nAfter bubble sort:\narr = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
