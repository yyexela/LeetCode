#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void printVec(vector<double> vec){
    cout<<"[";
    for(vector<double>::iterator i = vec.begin(); i != vec.end()-1; ++i){
        cout<<*i<<",";
    }
    cout<<*(vec.end()-1)<<"]"<<endl;
}

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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return vector<double>();
        vector<double> out;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(stack.size() != 0){
            double average = 0;
            int count = 0;
            for(int i = stack.size(); i >= 1; --i){
                if(stack.at(0)->left != NULL) stack.push_back(stack.at(0)->left);
                if(stack.at(0)->right != NULL) stack.push_back(stack.at(0)->right);
                average += stack.at(0)->val;
                ++count;
                stack.erase(stack.begin());
            }
            out.push_back(average/count);
        }
        return out;
    }
};

int main(){
    //balanced, should return true
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    cout<<"Tree:"<<endl;
    printBST(root);
    cout<<endl;
    Solution sol;
    vector<double> vec = sol.averageOfLevels(root);

    printVec(vec);
}