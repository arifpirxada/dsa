#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
            val = data;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
        TreeNode* root;

        BST(int val) {
            root = new TreeNode(val);
        }

        // Insertion

        void insert(TreeNode* node, int val) {
            if (node == NULL) return;

            if (val == node->val) {
                return;
            } else if (val < node->val) {
                // Go left
                if (node->left == NULL) {
                    node->left = new TreeNode(val);
                } else {
                    insert(node->left, val);
                }
            } else {
                // Go right
                if (node->right == NULL) {
                    node->right = new TreeNode(val);
                } else {
                    insert(node->right, val);
                }
            }
        }

        // Insert cleaner version - This version works even for an empty tree.
        // Call like this - tree.root = insert(tree.root, val);

        TreeNode* insertClearnerVersion(TreeNode* node, int val) {
            if (node == NULL) {
                return new TreeNode(val);
            }

            if (val < node->val) {
                node->left = insertClearnerVersion(node->left, val);
            } else if (val > node->val) {
                node->right = insertClearnerVersion(node->right, val);
            }

            return node;
        }

        

        // Level order Traversal

        vector<vector<int>> levelTraversal() {
            queue<TreeNode*> q;
            q.push(root);

            vector<vector<int>> arr;

            while (!q.empty()) {
                int len = q.size();
                vector<int> level;

                for (int i = 0; i < len; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    level.push_back(node->val);

                    if (node->left != NULL) {
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    }
                }
                arr.push_back(level);
            }

            return arr;
        }

        // Searching in BST

        bool search(TreeNode* node, int val) {
            if (node == NULL) return false;

            if (node->val == val) return true;

            if (node->val > val)
                return search(node->left, val);
            else
                return search(node->right, val);
        }

        // Deleteion - Learn deletion this has bugs

        TreeNode* inPredecessor(TreeNode* node) {
            node = node->left;

            while (node->right) {
                node = node->right;
            }
            return node;
        }

        TreeNode* inSuccessor(TreeNode* node) {
            node = node->right;

            while (node->left) {
                node = node->left;
            }
            return node;
        }
        

        TreeNode* deleteNode(TreeNode* node, int val) {
            if (!node) return NULL;

            if (node->val > val) {
                node->left = deleteNode(node->left, val);
            } else if (node->val < val) {
                node->right = deleteNode(node->right, val);
            } else {
                if (!node->left && !node->right) {
                    delete node;
                    return NULL;
                }

                if (node->left) {
                    // Delete using inorder predecessor
                    TreeNode* iPre = inPredecessor(node);
                    node->val = iPre->val;
                    node->left = deleteNode(node->left, iPre->val);
                } else {
                    // Delete using inorder successor
                    TreeNode* iSuc = inSuccessor(node);
                    node->val = iSuc->val;
                    node->right = deleteNode(node->right, iSuc->val);
                }
            }

            return node;
        }
};

int main() {
    vector<vector<int>> arr;
    BST tree(3);

    tree.insert(tree.root, 2);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 0);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, -3);
    tree.insert(tree.root, 1);

    arr = tree.levelTraversal();

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // if (tree.search(tree.root, 0)) {
    //     cout << endl << "Element exists!";
    // } else {
    //     cout << endl << "Element does not exist!";
    // }

    tree.deleteNode(2);

    cout << endl;

    arr = tree.levelTraversal();

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }




    return 0;
}