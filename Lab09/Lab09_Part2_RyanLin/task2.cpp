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
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    return root;
}

bool checkTarget(TreeNode* root, int target){
    if(!root){
        return false;
    }
    if (root->val == target) {
        return true;
    }
    else if (target < root->val) {
        return checkTarget(root->left, target);
    }
    else{
        return checkTarget(root->right, target);
    }
}

int main(){
    int targetValue = 0;
    TreeNode* root = buildtree();
    while (true)
    {
        cout << "Target Value (-1 to exit): "<< endl;
        cin >> targetValue;
        if (targetValue == -1){
            break;
        }

        if (checkTarget(root, targetValue)) {
            cout << "Target " << targetValue << ", output: true" << endl;
        } else {
            cout << "Target " << targetValue << ", output: false" << endl;
        }
    }
    return 0;
   
}