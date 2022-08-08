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
    TreeNode* makeTreeFromArr(vector<int> &nums, int l, int r){
        if(l>r){
            return NULL;
        }
        // for sorted array, mid element should be taken for root for making balanced BST
        // tree will be in the form [l to mid-1] <-- [mid] --> [mid+1 to r]
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTreeFromArr(nums,l,mid-1);
        root->right = makeTreeFromArr(nums,mid+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTreeFromArr(nums, 0, nums.size()-1);
    }
};