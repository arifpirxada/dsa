/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<int> inorder;
    int index;

    void fill(TreeNode* node) {
        if (!node) return;

        fill(node->left);
        inorder.push_back(node->val);
        fill(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        fill(root);
    }
    
    int next() {
        return inorder[index++];
    }
    
    bool hasNext() {
        return index < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//  Using queue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    queue<int> q;
    void fill(TreeNode* node) {
        if (!node) return;

        fill(node->left);
        q.push(node->val);
        fill(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        fill(root);
    }
    
    int next() {
        int f = q.front();
        q.pop();
        return f;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */