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
    int count = 1, ans; // start from count=1 since index start from 1
    
    void inorder(TreeNode* root, int k){
        if(root==NULL){
            return;
        }
        inorder(root->left, k);
        if(count==k){
            ans = root->val;
        }
        count++;
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};