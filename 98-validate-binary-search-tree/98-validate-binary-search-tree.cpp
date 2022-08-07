/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, long minVal, long maxVal){
        if(root==NULL){
            return true;
        }
        // if root is a BST, its values should be between minVal and maxVal not including it
        if(root->val<=minVal || root->val>=maxVal){
            return false;
        }
        // check for the subtrees. for left/right subtree, all nodes should be lesser/greater than root
        return check(root->left, minVal, root->val) && check(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};