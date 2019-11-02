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
    int findSecondMinimumValue(TreeNode* root) {
        //if root is NULL, return -1
        if(root == NULL) return -1;

        //set variables absMin and currMin to root value, which is always the minimum in the tree
        int absMin, currMin;
        absMin = currMin = root->val;

        traverseTree(root, absMin, currMin);
        if(absMin == currMin)
            return -1;
        return currMin;
    }

    //goes through every node in the tree recursively, updating currMin
    //first update currMin to any value not equal to absMin
    //then, set currMin to any value lower than it if it isn't equal to absMin
    //exits with currMin as the lowest non-absMin value (if one exists)
    void traverseTree(TreeNode* node, int &absMin, int &currMin){
        if(currMin == absMin)
            currMin = node->val;
        if(node->val < currMin && node->val != absMin)
            currMin = node->val;
        if(node->left != NULL) traverseTree(node->left, absMin, currMin);
        if(node->right != NULL) traverseTree(node->right, absMin, currMin);
    }
};

int main(){
    //make tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(5);
    root->right = new TreeNode(8);

    //print tree
    cout<<"Tree:"<<endl;
    printBST(root);
    cout<<endl;

    //make solution
    Solution sol;
    int ans = sol.findSecondMinimumValue(root);
    cout<<"Answer: "<<ans<<endl;
}