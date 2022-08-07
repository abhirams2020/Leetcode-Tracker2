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
    unordered_map<int,int> idxMap;
    
    TreeNode* build(vector<int>& preorder, int i1, int j1, vector<int>& inorder, int i2, int j2){
        if(i2>j2){
            return NULL;
        }
        int currVal = preorder[i1];
        int currIdx = idxMap[currVal];
        TreeNode* root = new TreeNode(currVal);
        // let k be index of root in inorder. 
        // in inorder, i2 to k-1 index elements are in left subtree
        // after left part, k+1 to j2 index elements are in right subtree of root
        // in preorder after curr, take section = size of left subtree to find left, rest for right
        int leftSize = currIdx-i2; // i2 to k-1
        root->left = build(preorder, i1+1, i1+leftSize, inorder, i2, currIdx-1);
        root->right = build(preorder, i1+leftSize+1, j1, inorder, currIdx+1, j2);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            idxMap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};