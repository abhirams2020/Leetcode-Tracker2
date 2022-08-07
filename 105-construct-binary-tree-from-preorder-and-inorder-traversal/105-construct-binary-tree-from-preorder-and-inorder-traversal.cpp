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
// HARD TO THINK IN INTERVIEW. BELOW APPROACH MORE INTUITIVE
class Solution {
public:
    unordered_map<int,int> findIndexInorder;
    
    // using rootIndex to indicate pos of root index in preorder vector
    // rootIndex follows preorder traversal and increases after each node is visited
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        int curr = preorder[preorderIndex];
        TreeNode* newnode = new TreeNode(curr);
        
        int index=findIndexInorder[curr];
        // after visiting each node in preorder traversal, increment preorderIndex
        preorderIndex++;
        //preorderIndex value gets changed after successive calls to build the left subtree
        //Since it is passed as reference, updated value of preorderIndex is passed to build
        //the right subtree
        newnode->left = build(preorder, inorder, preorderIndex, inleft, index-1);
        newnode->right = build(preorder, inorder, preorderIndex, index+1, inright);
        return newnode;
    }

    // *Intuition* : First in preorder will be root. Find pos of root in inorder. 
    // Elements left to inorder is left of root, right to inorder is right of root
    // To find root->left, make new inorder as 0 to index-1 of present inorder.
    // New preorder should be from range 1 to size of new left inorder
    // Similar process for finding root->right. Then return root.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            findIndexInorder[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return build(preorder, inorder, preorderIndex, 0, n-1);
    }
};
*/

class Solution {
public:
    unordered_map<int,int> findIndexInorder;
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(inleft>inright){
            return NULL;
        }
        int currVal = preorder[preleft];
        int currIdx = findIndexInorder[currVal];
        int leftTreeSize = currIdx-inleft;
        // first element in preorder is root value. let k be index of root in inorder. 
        // in inorder, i2 to k-1 index elements are in left subtree
        // after left part, k+1 to j2 index elements are in right subtree of root
        // in preorder after curr, take section = size of left subtree to find left, rest for right
        TreeNode* root = new TreeNode(currVal);
        root->left = solve(preorder, inorder, preleft+1, preleft+leftTreeSize, inleft, currIdx-1);
        root->right = solve(preorder, inorder, preleft+leftTreeSize+1, preright, currIdx+1, inright);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            findIndexInorder[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, n-1, 0, n-1);
    }
};