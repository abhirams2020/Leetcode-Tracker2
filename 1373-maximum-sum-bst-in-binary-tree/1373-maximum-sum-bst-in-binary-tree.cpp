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
// USING DP FOR CHECK AND SUM FUNCTION
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

// RETURN MINLIMIT, MAXLIMIT, SUM AS VECTOR. RETURN {} IF NOT BST
class Solution {
public:
    int maxSum = 0;
    // {smallest_num, largest_num, curr_sum} of a tree
    vector<int> traverse(TreeNode* root) {
        if (!root)
            return {INT_MAX, INT_MIN, 0};
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);
		// check if a tree is BST
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0])
            return {};
		// if BST, update ans
        int currSum = root->val + left[2] + right[2];
        maxSum = max(maxSum, currSum);
        // min(left[0],curr) when we visit leaf node we return inf as minval
        return {min(left[0], root->val), max(right[1], root->val), currSum};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse(root);
        return maxSum;
    }
};
*/

// USING CLASS AS RETURN TYPE TO REDUCE MEMORY USAGE
class DataNode{
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution {
public:
    // 0 is min possible value. if tree sum is -ve NULL tree is returned with sum = 0
    int maxSum = 0;
    
    DataNode solve(TreeNode* root)
    {
        if(!root){
            // return INT_MIN as maxVal so that when parent checks right.minval < root->val it is true
            return {INT_MAX, INT_MIN, 0, true};
        }
        
        DataNode left = solve(root->left);
        DataNode right = solve(root->right);
        
        int sum = root->val + left.sum + right.sum;
        
        bool isBST = false;
        
        if(left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val) {   
            isBST = true;
            maxSum = max(maxSum, sum);
        }
        // return minval as min(root->val, left.minval) because for leaf node, left.minval will be int_max
        return {min(root->val, left.minVal), max(root->val, right.maxVal), sum, isBST};
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};