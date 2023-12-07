#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

TreeNode* insertIntoTree(TreeNode* root, int val){
    TreeNode* newNode = new TreeNode(val);
    if(!root){
        return newNode;
    }
    TreeNode* node = root;
    TreeNode* parent = nullptr;

    while(node != nullptr){
        parent = node;
        if (val < node->val){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    if(val < parent->val){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    return root;
}

TreeNode* buildTree(vector<int>& nums){
    TreeNode* root = nullptr;
    for (int num: nums){
        root = insertIntoTree(root, num);
    }
    return root;
}

void inOrderTraverse(TreeNode* root){
    if (!root){
        return;
    }
    stack<TreeNode*> stk;
    TreeNode* node = root;

    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }

        node = stk.top();
        stk.pop();
        cout << node->val << " ";

        node = node->right;
    }
}
int main() {
    vector<int> nums = {1, 5, 4, 3, 8, 2, 6};

    TreeNode* root = buildTree(nums);

    cout << "In-order traversal: ";
    inOrderTraverse(root);
    cout << endl;

    return 0;
}