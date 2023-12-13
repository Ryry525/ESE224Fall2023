#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void deleteTree(Node* root)
{
	if (root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}

	return;
}

bool isMaxHeap(Node* root)
{
	// BASE CASE
	if (root == nullptr)
	{
		return true;
	}

	// SET CURRENT LOGIC BOOL FLAG TO DEFAULT TRUE
	bool currentFlag = true;

	if (root->left != nullptr)
	{
		currentFlag = currentFlag && (root->data >= root->left->data);
	}

	if (root->right != nullptr)
	{
		currentFlag = currentFlag && (root->data >= root->right->data);
	}

	return currentFlag && isMaxHeap(root->left) && isMaxHeap(root->right);
}

int main(){
    	// CREATE TREE
	Node* root = new Node(10);
	root->left = new Node(9);
	root->right = new Node(8);
	root->left->left = new Node(7);
	root->left->right = new Node(10);
	root->right->left = new Node(5);
	root->right->right = new Node(4);
	root->left->left->left = new Node(3);
	root->left->left->right = new Node(2);
	root->left->right->left = new Node(1);

	cout << "Tree is max heap: " << (isMaxHeap(root) ? "True" : "False") << endl;

	deleteTree(root);
	return 0;
}