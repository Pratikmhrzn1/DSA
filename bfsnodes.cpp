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

    // Insert function (BST)
    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // BFS Traversal
    void bfs(Node* node) {
        if (node == NULL) return;

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
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        tree.insert(value);
    }

    cout << "BFS Traversal: ";
    tree.displayBFS();
	cout<<"\nPratik Maharjan";
    return 0;
}
