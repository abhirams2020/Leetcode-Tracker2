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
    vector<vector<int>> validPaths;
    
    void dfs(TreeNode* root, vector<int> &path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            validPaths.push_back(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        vector<string> ans;
        for(auto v:validPaths){
            string currPath;
            for(int i=0;i<v.size();i++){
                if(i!=v.size()-1)
                    currPath += to_string(v[i]) + "->";
                else
                    currPath += to_string(v[i]);
            }
            ans.push_back(currPath);
        }
        return ans;
    }
};