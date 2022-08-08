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
    // function to find first index of value larger than key
    int findFirstLargeIndex(vector<int> &nums, int key, int l, int r){
        // if all elements greater than key, return l as first index
        // if all elements less than key, return r+1 as first index
        if(key < nums[l]){
            return l;
        }
        if(key > nums[r]){
            return r+1;
        }
        while(r-l>1){
            int mid = l+(r-l)/2;
            if(nums[mid]<=key){
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        if(nums[l]>=key){
            return l;
        }
        return r;
    }
    
    TreeNode* makeTreeFromPreorder(vector<int> &preorder, int l, int r){
        if(l>r){
            return NULL;
        }
        if(l==r){
            return new TreeNode(preorder[l]);
        }
        // first element in preorder is taken as root. 
        // all smaller or equal elements after it is left subtree. 
        // all greater elements after it is right subtree
        // find index of first number greater than preorder[l]
        int k = findFirstLargeIndex(preorder, preorder[l], l+1, r);
        
        TreeNode* root = new TreeNode(preorder[l]);
        root->left = makeTreeFromPreorder(preorder, l+1, k-1);
        root->right = makeTreeFromPreorder(preorder, k, r);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeTreeFromPreorder(preorder, 0, preorder.size()-1);
    }
};