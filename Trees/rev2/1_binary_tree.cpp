#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val, Node* left = nullptr, Node* right = nullptr) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class BinaryTree {
public:

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    void preorder(Node* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    // Inserts in level order
    void insert(Node* root, int val) {
        queue<Node*> q;

        q.push(root);

        while (!q.empty()) {
            Node* node = q.front(); q.pop();

            if (!node->left) {
                node->left = new Node(val);
                return;
            } else {
                q.push(node->left);
            }

            if (!node->right) {
                node->right = new Node(val);
                return;
            } else {
                q.push(node->right);
            }
        }
    }

    Node* deleteNode(Node* root, int val) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        Node* target = nullptr;
        Node* last = nullptr;
        Node* lastParent = nullptr;

        while (!q.empty()) {
            last = q.front(); q.pop();

            if (last->val == val) target = last;

            if (last->left) {
                lastParent = last;
                q.push(last->left);
            }
            if (last->right) {
                lastParent = last;
                q.push(last->right);
            }
        }

        if (!target) return root;

        // Copy deepest rightmost value into target
        target->val = last->val;

        // Delete the deepest rightmost node via its parent
        if (lastParent->right == last) {
            delete lastParent->right;
            lastParent->right = nullptr;
        } else {
            delete lastParent->left;
            lastParent->left = nullptr;
        }

        return root;
    }
};

int main () {
    return 0;
}