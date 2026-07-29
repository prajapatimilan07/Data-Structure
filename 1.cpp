#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int choice;

    while (true) {
        cout << "\n--- Array Operations Menu ---\n";
        cout << "1. Traversal (Print Array)\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Array elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 2: {
            int element, index;
            cout << "Enter element to insert: ";
            cin >> element;
            cout << "Enter index (0 to " << size << "): ";
            cin >> index;

            if (size >= 10 || index < 0 || index > size) {
                cout << "Invalid index or array full!\n";
            } else {
                for (int i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = element;
                size++;

                cout << "Element inserted successfully.\n";
                cout << "Updated array: ";
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }

        case 3: {
            int index;
            cout << "Enter index to delete (0 to " << size - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= size) {
                cout << "Invalid index!\n";
            } else {
                for (int i = index; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;

                cout << "Element deleted successfully.\n";
                cout << "Updated array: ";
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }

        case 4: {
            int target, foundIndex = -1;
            cout << "Enter element to search: ";
            cin >> target;

            for (int i = 0; i < size; i++) {
                if (arr[i] == target) {
                    foundIndex = i;
                    break;
                }
            }

            if (foundIndex != -1)
                cout << "Element found at index " << foundIndex << endl;
            else
                cout << "Element not found." << endl;

            cout << "Current array: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }

        case 5:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}