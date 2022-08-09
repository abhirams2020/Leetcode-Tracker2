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
    unordered_set<int> s;
    bool flag = false;
    
    void inorder(TreeNode* root, int target){
        if(root==NULL){
            return;
        }
        inorder(root->left,target);
        
        int curr = root->val;
        if(s.count(target-curr)){
            flag = true;
        }
        s.insert(curr);
        
        inorder(root->right,target);
    }
    
    // add elements to set inorder and check if target-curr exist in set
    bool findTarget(TreeNode* root, int k) {
        inorder(root, k);
        return flag;
    }
};