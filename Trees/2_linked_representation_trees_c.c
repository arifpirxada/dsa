#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val);
// traversal functions
void preOrder(Node *root);
void postOrder(Node *root);
void inOrder(Node *root);
int isBST(Node *root);
Node *searchBST(Node *root, int val); // O(log n) - O(n)
Node *iterativeSearchBST(Node *root, int val);


int main()
{
    Node *parent = createNode(5);
    Node *left = createNode(3);
    Node *right = createNode(7);

    Node *l = createNode(1);
    Node *r = createNode(4);
    
    parent->left = left; // Linking the node
    parent->right = right;

    left->left = l;
    left->right = r;
    // printf("Parent: %d, left: %d, right: %d\n", parent->data, left->data, right->data);

    // preOrder(parent);
    // postOrder(parent);
    // inOrder(parent);

    // if (isBST(parent)) {
    //     printf("Yes! it is a Binary Tree.");
    // } else {
    //     printf("No! it is not a Binary Tree.");
    // }

    // Searching

    // Node *ptr = searchBST(parent, 1);
    // if (ptr) {
    //     printf("Found: %d", ptr->data);
    // } else {
    //     printf("Element not found!");
    // }

    return 0;
}

Node* createNode(int val) {
    Node *nodePtr = (Node*)malloc(sizeof(Node));
    nodePtr->data = val;
    nodePtr->left = NULL;
    nodePtr->right = NULL;

    return nodePtr;
}

void preOrder(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(Node *root) {
    static Node *prev = NULL;
    if (root) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else {
        return 1;
    }
}

Node *searchBST(Node *root, int val) {
    if (root) {
        if (root->data == val) {
            return root;
        }
        if (root->data > val) {
            return searchBST(root->left, val);
        }
        searchBST(root->right, val);
    } else {
        return NULL;
    }
}

Node *iterativeSearchBST(Node *root, int val) {
    while (root)
    {
        if (root->data == val) {
            return root;
        } else if (root->data > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}