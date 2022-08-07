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
    bool check(TreeNode* root, long long minVal, long long maxVal){
        if(root==NULL){
            return true;
        }
        // minVal and maxVal are min and max possible values possible for root if it is a BST
        if(root->val>maxVal || root->val<minVal){
            return false;
        }
        // check for the subtrees. for left/right subtree, all nodes should be lesser/greater than root
        return check(root->left, minVal, (long long)root->val-1) && check(root->right, (long long)root->val+1, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};