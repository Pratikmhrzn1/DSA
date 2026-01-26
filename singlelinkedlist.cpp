#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Singly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, x;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                list.insertAtEnd(x);
                break;
            case 2:
                list.deleteFromBeginning();
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

