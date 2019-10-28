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
        cout<<" L:"<<root->right->val;

    cout<<endl;

    if(root->left != NULL)
        printBST(root->left);
    if(root->right != NULL)
        printBST(root->right);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        if(root->right != NULL){
            if(root->right->val <= root->val) return false;
            if(!isValidBST(root->right)) return false;
        }
                
        if(root->left != NULL){
            if(root->left->val >= root->val) return false;
            if(!isValidBST(root->left)) return false;
        }
        
        return true;
    }
};

int main(){
    //make BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->left = new TreeNode(6);

    printBST(root);

    cout<<endl<<endl;

    Solution sol;
    if(sol.isValidBST(root))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}