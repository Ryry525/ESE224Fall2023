#include <iostream>
#include <queue>
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    return root;
}

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    else{
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
}

int main(){
    TreeNode* root = buildtree();
    int depth = maxDepth(root);
    cout << "Maximum depth: " << depth << endl;
}