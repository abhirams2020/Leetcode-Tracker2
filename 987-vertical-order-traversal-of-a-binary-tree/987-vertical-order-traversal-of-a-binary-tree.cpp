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
    using pii = pair<int,int>;
    
    static bool cmp(pii &a, pii &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // dist[vertical] level gives {horizontal level, value of node}
        // required since if same horizontal and vertical level, sort by value
        map<int,vector<pair<int,int>>> dist;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                TreeNode* curr = it.first;
                int distFromRoot = it.second;
                dist[distFromRoot].push_back({level,curr->val});
                q.pop();
                if(curr->left){
                    q.push({curr->left, distFromRoot-1});
                }
                if(curr->right){
                    q.push({curr->right, distFromRoot+1});
                }
            }
            level++;
        }
        
        vector<vector<int>> ans;
        
        for(auto [k,v]:dist){
            sort(v.begin(), v.end(), cmp);
            vector<int> temp;
            for(auto i:v){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};