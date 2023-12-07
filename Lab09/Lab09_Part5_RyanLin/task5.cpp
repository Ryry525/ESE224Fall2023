#include <iostream>
using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

TreeNode* buildtree(){
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left= new TreeNode(4);
    root->right->right= new TreeNode(3);

    return root;
}

bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
    if (leftNode == nullptr && rightNode == nullptr) {
        return true;
    }
    if (leftNode == nullptr || rightNode == nullptr) {
        return false;
    }
    return (leftNode->val == rightNode->val) &&
           isSymmetric(leftNode->left, rightNode->right) &&
           isSymmetric(leftNode->right, rightNode->left);
}

bool isSymmetricTree(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

int main() {
    TreeNode* root = buildtree(); 

    if (isSymmetricTree(root)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}