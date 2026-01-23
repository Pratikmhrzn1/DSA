#include <iostream>
using namespace std;

class PriorityQueue {
    int *array;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        array = new int[capacity];
    }

    void enqueue(int x) {
        if (size == capacity) {
            cout << "The priority queue is full!\n";
            return;
        }

        int i;
        // Insert element in sorted order (descending priority)
        for (i = size - 1; i >= 0 && array[i] < x; i--) {
            array[i + 1] = array[i];
        }
        array[i + 1] = x;
        size++;

        cout << "The number has been added successfully!" << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "The priority queue is empty!\n";
            return;
        }

        cout << "Removed element: " << array[0] << endl;

        // Shift elements left
        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    void traverse() {
        if (size == 0) {
            cout << "The priority queue is empty!" << endl;
            return;
        }

        cout << "The elements of the priority queue are:" << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(4);
    int choice;

    do {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Enter a data in the queue: ";
                cin >> x;
                pq.enqueue(x);
                break;
            }
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.traverse();
                break;
            case 4:
                cout << "Exiting...!";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 4);

    return 0;
}

