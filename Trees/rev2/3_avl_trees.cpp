#include <iostream>

using namespace std;

class Node {
public:
    int val;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        height = 1;
        left = nullptr; right = nullptr;
    }
};

class AVLTree {
    int getHeight(Node* root) {
        if (!root) return 0;
        return root->height;
    }
    int getBalanceFactor(Node* root) {
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* rightRotate(Node* x) {
        Node* y = x->left;
        Node* t2 = y->right;

        x->left = t2;
        y->right = x;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        x->right = t2;
        y->left = x;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    Node* insert(Node* root, int val) {
        if (!root) {
            return new Node(val);
        }
        if (root->val > val) {
            root->left = insert(root->left, val);
        } else if (root->val < val) {
            root->right = insert(root->right, val);
        } else {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        // Check which case
        if (bf > 1 && root->left->val > val) {
            // LL
            root = rightRotate(root);
        } else if (bf < -1 && root->right->val < val) {
            // RR
            root = leftRotate(root);
        } else if (bf > 1 && root->left->val < val) {
            // LR
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        } else if (bf < -1 && root->right->val > val) {
            // RL
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }

        return root;
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

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        if (bf > 1 && getBalanceFactor(root->left) >= 0) {
            // LL
            root = rightRotate(root);
        } else if (bf < -1 && getBalanceFactor(root->right) <= 0) {
            // RR
            root = leftRotate(root);
        } else if (bf > 1 && getBalanceFactor(root->left) < 0) {
            // LR
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        } else if (bf < -1 && getBalanceFactor(root->right) > 0) {
            // RL
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }

        return root;
    }
};

int main () {
    return 0;
}