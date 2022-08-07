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
    unordered_map<int,int> findIndexInorder;
    
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int postleft, int postright, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        // in postorder, rightmost in preorder is root
        int currVal = postorder[postright];
        int currIdx = findIndexInorder[currVal];
        int rightTreeSize = inright - currIdx;
        // last element in postorder is root value. let k be index of root in inorder. 
        // in inorder, i2 to k-1 index elements are in left subtree
        // after left part, k+1 to j2 index elements are in right subtree of root
        // in postorder before curr, take section = size of right subtree to find right, rest for left
        TreeNode* root = new TreeNode(currVal);
        root->right = solve(postorder, inorder, postright-rightTreeSize, postright-1, currIdx+1, inright);
        root->left = solve(postorder, inorder, postleft, postright-rightTreeSize-1, inleft, currIdx-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {        
        int n = inorder.size();
        for(int i=0;i<n;i++){
            findIndexInorder[inorder[i]] = i;
        }
        return solve(postorder, inorder, 0, n-1, 0, n-1);
    }
};