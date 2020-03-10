#include <iostream>
using namespace std;

struct node {
    int data;
    int pos;
    node* left;
    node* right;
};

node* Insert(node* root, int data, int pos) {
    if (root == NULL) {
        cout << pos << "\n";
        node* n = new node();
        n->data = data;
        n->pos = pos;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (data < root->data) {
        root->left = Insert(root->left, data, 2 * pos);
        return root;
    }
    if (data > root->data) {
        root->right = Insert(root->right, data, 2 * pos + 1);
        return root;
    }
    return root;
}

node* Delete(node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        cout << root->pos << "\n";
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            node* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delete(root->right, root->data);
        }
    }
    return root;
}


int main() {
    node* root = NULL;
    int t;
    cin >> t;
    while (t--) {
        char ch;
        int a;
        cin >> ch >> a;
        if (ch == 'i') {
            root = Insert(root, a, 1);
        }
        else {
            root = Delete(root, a);
        }
    }
    return 0;
}
