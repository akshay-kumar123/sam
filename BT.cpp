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

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	
	inorder(root->right);
	cout << root->data << " ";
}

int height(Node *root){
	if(root == NULL) return 0;
	return max(height(root->left), height(root->right))+1;

}

void givenlevel(Node *root, int level){
	if(root == NULL) return;
	if(level == 1) cout << root->data << " ";
	else{
		givenlevel(root->left,level-1);
		givenlevel(root->right,level-1);
	}
}

void levelorder(Node *root){
	int i;
	for(i=height(root);i>0;i--){
		givenlevel(root,i);
	}
}



int main(){
	int i,j;
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	levelorder(root);
	return 1;
}