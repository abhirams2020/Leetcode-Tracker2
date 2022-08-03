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
/*
// USING SEPERATE FUNCTION FOR FINDING MAX DEPTH OF TREE. FOR EACH WE NEED TO FIND DEPTH. NOT EFFICIENT
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
*/

class Solution {
public:
    int maxTreeDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }        
        int leftH = maxTreeDepth(root->left);
        int rightH = maxTreeDepth(root->right);
        // if any subtree is not valid, return -1
        if(leftH==-1 || rightH==-1){
            return -1;
        }
        // if subtrees valid, compare height of both
        if(abs(leftH-rightH)>1){
            return -1;
        }        
        return 1 + max(leftH, rightH);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        // -1 means tree is unbalanced. if any of right or left subtree is unbalanced, -1 is returned
        return maxTreeDepth(root)!=-1;
    }
};