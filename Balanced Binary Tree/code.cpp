#include<iostream>
#include<vector>
#include<cmath>

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        vector<TreeNode*> stack;
        int count = 0, height = -1;
        stack.push_back(root);
        
        while(stack.size() != 0){
            for(int i = 0; i < stack.size(); ++i){
                if(stack.at(0)->left != NULL) stack.push_back(stack.at(0)->left);
                if(stack.at(0)->right != NULL) stack.push_back(stack.at(0)->right);
                stack.erase(stack.begin());
                ++count;
            }
            ++height;
        }

        cout<<"count: "<<count<<endl;
        cout<<"height: "<<height<<endl;

        if(count < pow(2,height)) return false;
        return true;
    }
};

int main(){
    //balanced, should return true
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->left = new TreeNode(12);
    cout<<"Tree:"<<endl;
    printBST(root);
    cout<<endl;
    Solution sol;
    if(sol.isBalanced(root))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    cout<<endl;

    //unbalanced tree, should return false;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->left->left = new TreeNode(11);
    cout<<"Tree:"<<endl;
    printBST(root);
    if(sol.isBalanced(root))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    cout<<endl;
}