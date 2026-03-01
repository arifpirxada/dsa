#include <iostream>
#include <queue>

using namespace std;

// AVL Tree - An AVL is a self-balancing Binary Search Tree (BST)

/*

Operations for balancing: left & right rotation.

Cases:

1. LL - insert / delete in left subtree of left child of first unbalanced ancestor.
2. RR - insert / delete in right subtree of right child of first unbalanced ancestor.
3. LR - insert / delete in right subtree of left child of first unbalanced ancestor.
5. RL - insert / delete in left subtree of right child of first unbalanced ancestor

First unbalanced ancestor - The first unbalanced node encountered while moving upward after insertion/deletion.

Operations: 

1. Insertion - 

2. Deletion

*/

class TreeNode {
    public:
        int val;
        int height;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            this->val = val; 
            height = 1;
            left = nullptr;
            right = nullptr;
        }
};

class AVLTree {
    public:
        TreeNode* root;

        AVLTree() {
            root = nullptr;
        }

        // Operations

        int getHeight(TreeNode* node) {
            if (!node) return 0;
            return node->height;
        }

        int getBalanceFactor(TreeNode* node) {
            return getHeight(node->left) - getHeight(node->right);
        }

        TreeNode* leftRotate(TreeNode* x) {
            TreeNode* y = x->right;
            TreeNode* t2 = y->left;

            x->right = t2;
            y->left = x;

            x->height = 1 + max(getHeight(x->left), getHeight(x->right));
            y->height = 1 + max(getHeight(y->left), getHeight(y->right));

            return y;
        }

        TreeNode* rightRotate(TreeNode* x) {
            TreeNode* y = x->left;
            TreeNode* t2 = y->right;

            x->left = t2;
            y->right = x;

            x->height = 1 + max(getHeight(x->left), getHeight(x->right));
            y->height = 1 + max(getHeight(y->left), getHeight(y->right));

            return y;
        }

        // ---

        TreeNode* insert(TreeNode* node, int val) {
            if (!node) {
                return new TreeNode(val);
            }
            if (node->val > val) {
                node->left = insert(node->left, val);
            } else if (node->val < val) {
                node->right = insert(node->right, val);
            } else {
                return node;
            }

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            int bf = getBalanceFactor(node);

            // Check which case
            if (bf > 1 && node->left->val > val) {
                // LL
                node = rightRotate(node);
            } else if (bf < -1 && node->right->val < val) {
                // RR
                node = leftRotate(node);
            } else if (bf > 1 && node->left->val < val) {
                // LR
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            } else if (bf < -1 && node->right->val > val) {
                // RL
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }

            return node;
        }

        // Traverse

        void levelOrder(TreeNode* node) {
            if (!node) return;

            queue<TreeNode*> q;
            q.push(node);
            
            vector<vector<int>> arr;

            while(!q.empty()) {
                int len = q.size();
                vector<int> level;

                for (int i = 0; i < len; i++) {
                    TreeNode* f = q.front();
                    q.pop();

                    level.push_back(f->val);

                    if (f->left)
                        q.push(f->left);
                    if (f->right)
                        q.push(f->right);
                }
                arr.push_back(level);
            }

            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr[i].size(); j++) {
                    cout << arr[i][j] << " ";
                }
            }
        }
};

int main() {
    AVLTree tree;

    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 10);

    /*
    Expect: 6 4 7 3 5 10, check, dry run using pen and paper, perform rotations

             6
           /    \
         4       7
       /  \        \
      3    5       10

    */

    cout << "Traverse 1: ";
    tree.levelOrder(tree.root);

    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 15);

    /*
    Expect: 6 4 7 3 5 12 10 12

             6
           /    \
         4       10
       /  \     /   \
      3    5   7    12
                      \
                       15
    */
    
    cout << endl << "Traverse 2: ";
    tree.levelOrder(tree.root);


    return 0;
}