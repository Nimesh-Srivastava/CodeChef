#include <iostream>
using namespace std;

struct node {
	int data;
	int pos; 
	node* left;
	node* right;
};

node* ins(node* root, int data, int pos) {
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
		root->left = ins(root->left, data, 2*pos);
		return root;
	}
	if (data > root->data) {
		root->right = ins(root->right, data, 2*pos+1);
		return root;
	}
	return root;
}

node* del(node* root, int data) {
	if (root == NULL) {
		return root;
	}
	if (data < root->data) {
		root->left = del(root->left, data);
	}
	else if (data > root->data) {
		root->right = del(root->right, data);
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
			root->right = del(root->right, root->data);
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
		int n;
		cin >> ch >> n;
		if (ch == 'i') {
			root = ins(root, n, 1);
		}
		else {
			root = del(root, n);
		}
	}
	return 0;
}