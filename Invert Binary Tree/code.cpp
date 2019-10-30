#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printBST(TreeNode* root){
    cout<<root->val;
    if(root->left != NULL)
        cout<<" L:"<<root->left->val;
    if(root->right != NULL)
        cout<<" R:"<<root->right->val;

    cout<<endl;

    if(root->left != NULL)
        printBST(root->left);
    if(root->right != NULL)
        printBST(root->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        return flipBST(root);
    }

    TreeNode* flipBST(TreeNode* node){
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->right != NULL) flipBST(node->right);
            if(node->left != NULL) flipBST(node->left);
            return node;
    }
};

int main(){
    //make BST
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    printBST(root);
    cout<<endl<<endl;
    Solution sol;
    TreeNode* tmp = sol.invertTree(root);
    printBST(tmp);
}