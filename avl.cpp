#include <iostream>
using namespace std;

class AVL {
    class Node {
    public:
        int data, height;
        Node *left, *right;

        Node(int v) {
            data = v;
            height = 1;
            left = right = NULL;
        }
    };

    Node* root;

    int h(Node* n) { return n ? n->height : 0; }
    int max(int a, int b) { return (a > b) ? a : b; }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = max(h(x->left), h(x->right)) + 1;
        y->height = max(h(y->left), h(y->right)) + 1;
        return y;
    }

    int balance(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

    Node* insert(Node* r, int v) {
        if (!r) return new Node(v);

        if (v < r->data) r->left = insert(r->left, v);
        else if (v > r->data) r->right = insert(r->right, v);
        else return r;

        r->height = 1 + max(h(r->left), h(r->right));
        int b = balance(r);

        if (b > 1 && v < r->left->data) return rightRotate(r);
        if (b < -1 && v > r->right->data) return leftRotate(r);
        if (b > 1 && v > r->left->data) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        if (b < -1 && v < r->right->data) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    void inorder(Node* r) {
        if (r) {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

public:
    AVL() { root = NULL; }

    void batchInsert() {
        int n, x;
        cout << "Enter the size: ";
        cin >> n;
        cout << "Enter values:\n";
        while (n--) {
            cin >> x;
            root = insert(root, x);
        }
    }

    void display() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL t;
    int ch;

    do {
        cout << "\n1.Insert (Batch)\n2.Display\n3.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) t.batchInsert();
        else if (ch == 2) t.display();

    } while (ch != 3);
	cout<<"\nPratik Maharjan\n";
    return 0;
}
