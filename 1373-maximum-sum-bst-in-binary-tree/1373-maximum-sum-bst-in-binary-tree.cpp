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
    map<pair<TreeNode*,pair<int,int>>, int> checkDp;
    
    bool check(TreeNode* root, int minVal, int maxVal){
        if(root==NULL){
            return true;
        }
        if(checkDp.count({root,{minVal,maxVal}})){
            return checkDp[{root,{minVal,maxVal}}];
        }
        // if root is a BST, its values should be between minVal and maxVal not including it
        if(root->val<=minVal || root->val>=maxVal){
            return checkDp[{root,{minVal,maxVal}}] = false;
        }
        // check for the subtrees. for left/right subtree, all nodes should be lesser/greater than root
        return checkDp[{root,{minVal,maxVal}}] = check(root->left, minVal, root->val) && check(root->right, root->val, maxVal);
    }
    
    unordered_map<TreeNode*,int> sumDp;
    
    int getSumBst(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(sumDp.count(root)){
            return sumDp[root];
        }
        int curr = root->val;
        int left = getSumBst(root->left);
        int right = getSumBst(root->right);
        return sumDp[root] = curr + left + right;
    }
    
    int maxSumBST(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = INT_MIN;
        if(check(root,INT_MIN,INT_MAX)){
            ans = getSumBst(root);
        }
        return max({ans, maxSumBST(root->left), maxSumBST(root->right)});
    }
};