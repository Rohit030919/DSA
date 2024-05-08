#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Entry {
    string keyword;
    string meaning;
};

class AVLNode {
public:
    Entry data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(Entry entry) {
        data = entry;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    AVLNode *root;

    AVLTree() {
        root = NULL;
    }

    int getHeight(AVLNode *node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode *node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *rightRotate(AVLNode *y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode *leftRotate(AVLNode *x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode *insertNode(AVLNode *node, Entry entry) {
        if (node == NULL)
            return new AVLNode(entry);

        if (entry.keyword < node->data.keyword)
            node->left = insertNode(node->left, entry);
        else if (entry.keyword > node->data.keyword)
            node->right = insertNode(node->right, entry);
        else {
            cout << "Duplicate keywords not allowed" << endl;
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && entry.keyword < node->left->data.keyword)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && entry.keyword > node->right->data.keyword)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && entry.keyword > node->left->data.keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && entry.keyword < node->right->data.keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void displayDictionary(AVLNode *node) {
        if (node != NULL) {
            displayDictionary(node->left);
            cout << node->data.keyword << ": " << node->data.meaning << endl;
            displayDictionary(node->right);
        }
    }

    AVLNode *searchKeyword(AVLNode *node, string keyword, int &comparisons) {
        if (node == NULL) {
            cout << "Keyword not found!" << endl;
            return NULL;
        }

        comparisons++;

        if (keyword == node->data.keyword) {
            cout << "Meaning of " << keyword << ": " << node->data.meaning << endl;
            return node;
        } else if (keyword < node->data.keyword) {
            return searchKeyword(node->left, keyword, comparisons);
        } else {
            return searchKeyword(node->right, keyword, comparisons);
        }
    }
};

int main() {
    int choice;
    string keyword, meaning;
    AVLTree avlTree;

    while (true) {
        cout << "1. Insert a keyword" << endl;
        cout << "2. Display dictionary" << endl;
        cout << "3. Search for a keyword" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin >> meaning;
                avlTree.root = avlTree.insertNode(avlTree.root, Entry{keyword, meaning});
                break;

            case 2:
                cout << "Dictionary:" << endl;
                avlTree.displayDictionary(avlTree.root);
                break;

            case 3:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                int comparisons = 0;
                avlTree.searchKeyword(avlTree.root, keyword, comparisons);
                cout << "Number of comparisons: " << comparisons << endl;
                break;
        }
    }
}

