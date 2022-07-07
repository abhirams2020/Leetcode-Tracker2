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
    int widthOfBinaryTree(TreeNode* root) {
        // q -> {{Node,horizontal dist from root}}
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxWidth = 1;
        
        while(!q.empty()){
            int n = q.size();
            long long currMax = LONG_MIN;
            long long currMin = LONG_MAX;
            
            // for a level, if starting index is not 0, then we can change the starting index from 0
            // ie. in queue [3,4,6] will be changed to [0,1,3] by reducing 3 from all index
            int start = q.front().second;
            
            for(int i=0;i<n;i++){
                TreeNode* currNode = q.front().first;
                long long currIdx = q.front().second - start;
                q.pop();
                
                currMin = min(currMin, currIdx);
                currMax = max(currMax, currIdx);
                
                // for node with index = k, its left child have index = 2k and right child have index = 2k+1
                //             0
                //        0         1
                //     0     1   2     3
                //    0 1   2 3 4 5   6 7
                if(currNode->left!=NULL){
                    q.push({currNode->left,2LL*currIdx});
                }
                if(currNode->right!=NULL){
                    q.push({currNode->right,2LL*currIdx+1});
                }
            }
            
            long long currWidth = currMax - currMin + 1;
            maxWidth = max(maxWidth, currWidth);
        }
        
        return (int)maxWidth;
    }
};