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
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        // if not same level sort by level
        if(a.second != b.second){
            return a.second < b.second;
        }
        // if same level sort by value
        return a.first < b.first;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // mp[Dist from root] = {Node address, level}
        map<int,vector<pair<int,int>>> mp;
        int level = 0;
        // q = {Node address, dist from root}
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* curr = it.first;
                int distFromRoot = it.second;
                mp[distFromRoot].push_back({curr->val,level});
                if(curr->left){
                    q.push({curr->left,distFromRoot-1});
                }
                if(curr->right){
                    q.push({curr->right,distFromRoot+1});
                }
            }
            level++;
        }
        
        vector<vector<int>> ans;
        
        for(auto [k,v]:mp){
            sort(v.begin(),v.end(),cmp);
            vector<int> temp;
            for(auto i:v){
                temp.push_back(i.first);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};