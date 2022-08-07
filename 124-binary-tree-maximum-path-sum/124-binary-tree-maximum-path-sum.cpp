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
    int maxSum = INT_MIN;
    
    // maxPathFromRoot returns the max value with root as start and one child node as end
    int maxPathFromRoot(TreeNode* root) {
        if(!root){
            return 0;
        }
        // find max sum of subtrees of root which start from subtree node and ends in some child node
        int left = max(0, maxPathFromRoot(root->left));
        int right = max(0, maxPathFromRoot(root->right));
        
        // both added to root to get max path sum. if subtree sum less than 0, it is not considered
        int currSum = root->val + left + right;
        maxSum = max(maxSum, currSum);
        
        // maxPathFromRoot should start from root. so only go to left or right of root.
        return root->val + max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        maxPathFromRoot(root);
        return maxSum;
    }
};