#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = nullptr; right = nullptr;
    }
};

class BST {
    void insert(Node* root, int val) {
        Node* prev;
        while (root) {
            prev = root;
            if (root->val == val) {
                cout << val << " already exists!";
                return;
            } else if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        Node* newNode = new Node(val);
        if (prev->val > val) {
            root->left = newNode;
        } else {
            root->right = newNode;
        }
    }

    Node* inorderPredecessor(Node* root) {
        root = root->left;
        while(root->right) {
            root = root->right;
        }
        return root;
    }

    Node* inorderSuccessor(Node* root) {
        root = root->right;
        while(root->left) {
            root = root->left;
        }
        return root;
    }

    Node* deleteBST(Node* root, int val) {
        if (!root) return nullptr;

        if (val < root->val) {
            root->left = deleteBST(root->left, val);
        }
        else if (val > root->val) {
            root->right = deleteBST(root->right, val);
        }
        else { // found node to delete

            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            if (root->left) {
                Node* pred = inorderPredecessor(root);
                root->val = pred->val;
                root->left = deleteBST(root->left, pred->val);
            } else {
                Node* succ = inorderSuccessor(root);
                root->val = succ->val;
                root->right = deleteBST(root->right, succ->val);
            }
        }

        return root;
    }
};

int main () {
    return 0;
}