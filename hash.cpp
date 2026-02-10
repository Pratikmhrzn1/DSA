#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7);   // used in double hashing
    }

    void linearProbing(int key) {
        int index = hash1(key);
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }

    void quadraticProbing(int key) {
        int index = hash1(key);
        int i = 1;
        while (table[index] != -1) {
            index = (hash1(key) + i * i) % SIZE;
            i++;
        }
        table[index] = key;
    }

    void doubleHashing(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (table[index] != -1) {
            index = (index + step) % SIZE;
        }
        table[index] = key;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "EMPTY";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int choice, key;
    cout << "\n--- Hashing Menu ---";
        cout << "\n1. Insert using Linear Probing";
        cout << "\n2. Insert using Quadratic Probing";
        cout << "\n3. Insert using Double Hashing";
        cout << "\n4. Display Hash Table";
        cout << "\n5. Exit";

    do {
        
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            h.linearProbing(key);
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;
            h.quadraticProbing(key);
            break;

        case 3:
            cout << "Enter key: ";
            cin >> key;
            h.doubleHashing(key);
            break;

        case 4:
            h.display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
	cout<<"\nSwornima Dangol\n";
    return 0;
}
