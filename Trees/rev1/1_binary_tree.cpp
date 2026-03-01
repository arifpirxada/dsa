#include <iostream>
#include <queue>

using namespace std;

/*
- Create
- Insert
- Delete
- Traverse
- Search
 */

 class Node {
    public:
        int data;
        Node* right;
        Node* left;

        Node(int val) {
            data = val;
            right = NULL;
            left = NULL;
        }
 };

 class Tree {
    public:
        Node* root;
        Tree(int val) {
            root = new Node(val);
        }
        ~Tree() {
            // Traverse and delete
        }

        // Build

        Node* buildTree(Node* r) {
            int val;
            
            cout << " Enter Data: ";
            cin >> val;
            r = new Node(val);

            if (val == -1) return NULL;

            r->data = val;

            cout << "Left of " << val;
            r->left = buildTree(r->left);

            cout << "Right of " << val;
            r->right = buildTree(r->right);

            return r;
        }

        void build() {
            cout << "Left of " << root->data;
            root->left = buildTree(root->left);
            cout << "Right of " << root->data;
            root->right = buildTree(root->right);
        }

        // insert
        // insert the key into the binary tree at the first position available in level order manner.

        void insertMyApproach(int val) {
            if (root == NULL) return;

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                int len = q.size();
                for (int i = 0; i < len; i++) {
                    Node* node = q.front();
                    q.pop();

                    if (node->left != NULL) {
                        q.push(node->left);
                    } else {
                        node->left = new Node(val);
                        return;
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    } else {
                        node->right = new Node(val);
                        return;
                    }
                }
            }
        }

        void insertChatApproach(int val) {
            if (root == NULL) {
                root = new Node(val);
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node* node = q.front();
                q.pop();

                // Insert at first available left
                if (node->left == NULL) {
                    node->left = new Node(val);
                    return;
                } else {
                    q.push(node->left);
                }

                // Insert at first available right
                if (node->right == NULL) {
                    node->right = new Node(val);
                    return;
                } else {
                    q.push(node->right);
                }
            }
        }

        // Deletion

        /*
        Given a binary tree, the task is to delete a given node from it by making sure that the tree shrinks 
        from the bottom (i.e. the deleted node is replaced by the bottom-most and rightmost node). 
        This is different from BST deletion. Here we do not have any order among elements,
        so we replace them with the last element.
        */

        void deleteNode(int key) {
            if (root == NULL) return;

            // If only one node
            if (root->left == NULL && root->right == NULL) {
                if (root->data == key) {
                    delete root;
                    root = NULL;
                }
                return;
            }

            queue<Node*> q;
            q.push(root);

            Node* keyNode = NULL;
            Node* lastNode = NULL;
            Node* parentOfLast = NULL;

            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();

                if (temp->data == key)
                    keyNode = temp;

                if (temp->left) {
                    parentOfLast = temp;
                    q.push(temp->left);
                }

                if (temp->right) {
                    parentOfLast = temp;
                    q.push(temp->right);
                }

                lastNode = temp;
            }

            if (keyNode != NULL) {
                keyNode->data = lastNode->data;

                if (parentOfLast->right == lastNode)
                    parentOfLast->right = NULL;
                else
                    parentOfLast->left = NULL;

                delete lastNode;
            }
        }

        // Traversals: Level order, inorder, preorder, postorder

        void levelOrderTraverse() {
            if (root == NULL) return;

            queue<Node*> q;
            vector<vector<int>> ans;

            q.push(root);

            while (!q.empty()) {
                int len = q.size();
                vector<int> level;

                for (int i = 0; i < len; i++) {
                    Node* node = q.front();
                    q.pop();

                    level.push_back(node->data);

                    if (node->left != NULL)
                        q.push(node->left);

                    if (node->right != NULL)
                        q.push(node->right);
                }

                ans.push_back(level);
            }

            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < ans[i].size(); j++) {
                    cout << ans[i][j] << " ";
                }
            }
        }

        void inorderTraverse(Node* r) {
            if (r == NULL) return;

            inorderTraverse(r->left);
            cout << r->data << " ";
            inorderTraverse(r->right);
        }

        void preorderTraverse(Node* r) {
            if (r == NULL) return;

            cout << r->data << " ";
            preorderTraverse(r->left);
            preorderTraverse(r->right);
        }

        void postorderTraverse(Node* r) {
            if (r == NULL) return;

            postorderTraverse(r->left);
            postorderTraverse(r->right);
            cout << r->data << " ";
        }

        // Search
 };

 /*
 Test case:

          1
       /     \
      5       8
     / \     /  \
    4   9   2    1
   /     \        \
  3       2        1

  Level order: 1 5 8 4 9 2 1 3 2 1
  Inorder: 3 4 5 9 2 1 2 8 1 1
  Preorder: 1 5 4 3 9 2 8 2 1 1
  Postorder: 3 4 2 9 5 2 1 1 8 1

 */

 int main() {
    Tree tre(1);

    tre.build();

    cout << endl << "Level Order: ";
    tre.levelOrderTraverse();

    cout << endl << "Inorder: ";
    tre.inorderTraverse(tre.root);

    cout << endl << "Preorder: ";
    tre.preorderTraverse(tre.root);

    cout << endl << "Postorder: ";
    tre.postorderTraverse(tre.root);


    return 0;
 }