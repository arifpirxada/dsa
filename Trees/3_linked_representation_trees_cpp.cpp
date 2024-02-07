#include <iostream>
using std::cout;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value) : data(value), left(NULL), right(NULL) {}
} Node;

class BinaryTree
{
private:
    Node *root;

    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void preOrderTraversal(Node *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void preOrder() {
        preOrderTraversal(root);
    }
};

int main()
{
    BinaryTree myTree;
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.preOrder();

    return 0;
}