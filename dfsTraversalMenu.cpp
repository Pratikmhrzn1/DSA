#include <iostream>
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

    
    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }
};


int main() {
    BinaryTree tree;
    int choice, value;

    
        cout << "\n--- DFS Traversal Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.displayInorder();
            break;

        case 3:
            cout << "Preorder Traversal: ";
            tree.displayPreorder();
            break;

        case 4:
            cout << "Postorder Traversal: ";
            tree.displayPostorder();
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
	cout<<"\Pratik Maharjan";
    return 0;
}
