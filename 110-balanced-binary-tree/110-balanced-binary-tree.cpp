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
    int maxTreeDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + max(maxTreeDepth(root->left), maxTreeDepth(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftH = maxTreeDepth(root->left);
        int rightH = maxTreeDepth(root->right);
        // if height difference in left and right subtree is more than 1, not balanced
        if(abs(leftH-rightH)>1){
            return false;
        }
        // check if left and right subtree is balanced tree
        return isBalanced(root->left) && isBalanced(root->right);
    }
};