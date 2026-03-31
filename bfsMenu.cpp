#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
private:
    Node* root;

    // Insert into BST
    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // BFS Traversal (Level Order)
    void bfs(Node* node) {
        if (node == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << endl;
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void displayBFS() {
        bfs(root);
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    do {
        cout << "\n--- BFS Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "BFS Traversal: ";
            tree.displayBFS();
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
	cout<<"\nPratik Maharjan";
    return 0;
}
