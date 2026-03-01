#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/same-tree/?envType=problem-list-v2&envId=tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
    public:
        TreeNode* root;
        Tree(int val) {
            root = new TreeNode(val);
        }
        ~Tree() {
            // Traverse and delete
        }

        // Build

        TreeNode* buildTree(TreeNode* r) {
            int val;
            
            cout << " Enter Data: ";
            cin >> val;
            r = new TreeNode(val);

            if (val == -1) return NULL;

            r->val = val;

            cout << "Left of " << val;
            r->left = buildTree(r->left);

            cout << "Right of " << val;
            r->right = buildTree(r->right);

            return r;
        }

        void build() {
            cout << "Left of " << root->val;
            root->left = buildTree(root->left);
            cout << "Right of " << root->val;
            root->right = buildTree(root->right);
        }
 };

class Solution {
public:
    void preorder(TreeNode* node, vector<TreeNode*> *v) {
        if (node == NULL) {
            v->push_back(NULL);
            return;
        }

        v->push_back(node);
        preorder(node->left, v);
        preorder(node->right, v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv;
        vector<TreeNode*> pq;

        preorder(p, &pv);
        preorder(q, &pq);

        if (pv.size() != pq.size()) return false;

        for (int i = 0; i < pv.size(); i++) {
            if (pv[i] == NULL && pq[i] != NULL || pv[i] != NULL && pq[i] == NULL) {
                return false;
            }
            if (pv[i] == NULL && pq[i] == NULL) {
                continue;
            }
            if (pv[i]->val != pq[i]->val) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Tree p(1);
    Tree q(1);

    cout << "Build p: " << endl;
    p.build();

    cout << endl << "Build 1: " << endl;
    q.build();

    Solution s;

    if (s.isSameTree(p.root, q.root)) {
        cout << endl << "Yes is same";
    } else {
        cout << "Not same";
    }

    return 0;
}