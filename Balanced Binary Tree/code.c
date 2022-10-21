/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compareHeight(struct TreeNode* node);

bool isBalanced(struct TreeNode* root){
    // Recurse
    return compareHeight(root);
}

bool compareHeight(struct TreeNode* node){
    // Base condition
    if(node == NULL){return true;}
    
    // Check leaf heights
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);
    int diff = lh - rh;
    // Return false if different
    if(!(-1 <= diff && diff <= 1)){return false;}
    // Recurse if the same
    bool left = compareHeight(node->left);
    bool right = compareHeight(node->right);
    return left && right;
}

int getHeight(struct TreeNode* node){
    // Base Case
    if(node==NULL){
        return 0;
    }else if(node->left==NULL && node->right == NULL){
        return 1;
    }else if(node->right != NULL || node->left != NULL){
        int rh = 1 + getHeight(node->right);
        int lh = 1 + getHeight(node->left);
        return rh > lh ? rh : lh;
    }else{
        return 1 + getHeight(node->left);
    }
}
