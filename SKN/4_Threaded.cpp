#include<iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    bool isThreaded;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
        isThreaded = false;
    }
};

class ThreadedBinaryTree {
public:
    TreeNode *root;

    ThreadedBinaryTree() {
        root = NULL;
    }

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == NULL)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    void convertToThreaded(TreeNode *node, TreeNode *&prev) {
        if (node == NULL) return;

        convertToThreaded(node->left, prev);

        if (node->left == NULL) {
            node->left = prev;
            node->isThreaded = true;
        }

        if (prev != NULL && prev->right == NULL) {
            prev->right = node;
            prev->isThreaded = true;
        }

        prev = node;

        convertToThreaded(node->right, prev);
    }

    void inorderTraversal(TreeNode *node) {
    	
        if (node == NULL) return;
        while (node->left != NULL)
            node = node->left;

        while (node != NULL) {
            cout << node->data << " ";

            if (node->isThreaded)
                node = node->right;
            else {
                node = node->right;
                while (node != NULL && !node->isThreaded)
                    node = node->left;
            }
        }
    }
};

int main() {
    ThreadedBinaryTree tbt;

    int numNodes;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> numNodes;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cin >> value;
        tbt.root = tbt.insertNode(tbt.root, value);
    }

    TreeNode *prev = NULL;
    tbt.convertToThreaded(tbt.root, prev);

    cout << "Inorder traversal of threaded binary tree: ";
    tbt.inorderTraversal(tbt.root);
    cout << endl;

    return 0;
}

