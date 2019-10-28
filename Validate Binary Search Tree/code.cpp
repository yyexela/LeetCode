#include<iostream>
#include<vector>

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
        vector<int> vec;
        buildInOrder(root, vec);
        for(vector<int>::iterator i = vec.begin(); i < vec.end(); ++i){
            //cout<<"i: "<<*i<<endl;
            if(i != vec.begin() && (*i) <= *(i-1)){
                //cout<<"i: "<<*i<<" i-1:"<<*(i-1)<<endl;
                return false;
            }
        }
        return true;
    }

    void buildInOrder(TreeNode* root, vector<int>& vec){
        if(root->left != NULL)
            buildInOrder(root->left, vec);
        vec.push_back(root->val);
        if(root->right != NULL)
            buildInOrder(root->right, vec);
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