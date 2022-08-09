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
// USING FLATTEN FUNCTION RECURSIVELY
class Solution {
public:
    void flatten(TreeNode* root) {
        // if null node or single node, return
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        // for flattening the binary tree, we attach the left subtree to right of root
        // then rightmost node in left subtree is connected to previous right of root
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // if left is null, we dont need to connect left subtree to right
        if(left != NULL){
            // find rightmost in left subtree and connect it to head of right subtree
            TreeNode* temp = left;
            while(temp->right){
                temp = temp->right;
            }
            root->left = NULL;
            root->right = left;
            temp->right = right;
        }
        // repeat the same for subtrees of current tree
        flatten(root->left);
        flatten(root->right);
    }
};
*/

// USING REVERSE POSTORDER AND MAINTAINING A GLOBAL PREV POINTER
// AFTER FINDING THE LAST IN PREORDER, WE NEED TO MAKE CURR->NEXT AS PREV AND CURR->RIGHT AS NULL.
class Solution {
public:
    TreeNode* prev = NULL;
    
    void revPostorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        revPostorder(root->right);
        revPostorder(root->left);
        
        // make curr->right as prev and curr-left as NULL
        root->left = NULL;
        root->right = prev;
        // update prev
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        revPostorder(root);
    }
};