#include <iostream>
using namespace std;

// Binary Search function using a, l, r, k
int binarySearch(int a[], int l, int r, int k) {
    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int a[50], n = 0, choice, k;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enter array elements (sorted)\n";
        cout << "2. Display array\n";
        cout << "3. Binary Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements in sorted order:\n";
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
                int result = binarySearch(a, 0, n - 1, k);
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
	cout<<"\nPratik Maharjan\n";
    return 0;
}
