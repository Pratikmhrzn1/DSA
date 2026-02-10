#include <iostream>
using namespace std;

// Sequential (Linear) Search function using a, n, k
int sequentialSearch(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k)
            return i;
    }
    return -1;
}

int main() {
    int a[50], n = 0, choice, k;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enter array elements\n";
        cout << "2. Display array\n";
        cout << "3. Sequential Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            break;

        case 2:
            cout << "Array elements:\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> k;
            {
                int result = sequentialSearch(a, n, k);
                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found\n";
            }
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);
	cout<<"\nSwornima Dangol\n";
    return 0;
}
