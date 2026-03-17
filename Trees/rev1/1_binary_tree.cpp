/*
Binary Tree Implementation:

- Insert
- Delete
- Traversals

*/

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            this->val = val;
            left = nullptr;
            right = nullptr;
        }
}

class Tree {
    public:
        TreeNode* insert(TreeNode* root, int key) {
            if (!root) {
                return new TreeNode(val);
            }

            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                TreeNode* f = q.front();
                q.pop();

                if (!f->left) {
                    f->left = new TreeNode(key);
                    break;
                } else if (!f->right) {
                    f->right = new TreeNode(key);
                    break;
                }

                q.push(f->left);
                q.push(f->right);
            }

            return root;
        }

        TreeNode* deleteNode(TreeNode* root, int key) {
            if (!root) return root;

            
        }
}