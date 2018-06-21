#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left,*right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

class BST{
public:
	Node *root;
	BST(){
		root == NULL;
	}
	Node * insert(Node *r, int x){
		if(r == NULL) return new Node(x);
		else{
			if(r->data > x) r->left = insert(r->left, x);
			else r->right = insert(r->right, x);
		}
	}

	bool search(Node *r, int x){
		if(r == NULL) return false;
		if(r->data == x) return true;
		if(r->data > x) return search(r->left, x);
		else return search(r->right, x);
		return false;
	}

	int height(Node *r){
		if(r == NULL) return 0;
		return max(height(r->left), height(r->right))+1;

	}

	void givenlevel(Node *r, int level){
		if(r == NULL) return;
		if(level == 1) cout << r->data << " ";
		else{
			givenlevel(r->left,level-1);
			givenlevel(r->right,level-1);
		}
	}

	void levelorder(Node *r){
		int i;
		for(i=1;i<=height(r);i++){
			givenlevel(r,i);
		}
	}

	void inorder(Node *root){
		if(root == NULL) return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
		
	}
};

int main(){

	BST *b = new BST();
	b->root = b->insert(b->root,5);
	b->insert(b->root,2);
	b->insert(b->root,4);
	b->insert(b->root,10);
	b->insert(b->root,9);
	b->inorder(b->root);
	// cout << b->root->left->right->data;
	return 1;
}