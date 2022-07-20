class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> NGL(n); // nearest greater to left
        vector<int> NGR(n); // nearest greater to right
        
        int maxLeft=0, maxRight=0;
        for(int i=0;i<n;i++){
            maxLeft = max(heights[i], maxLeft);
            NGL[i] = maxLeft;
        }
        for(int i=n-1;i>=0;i--){
            maxRight = max(heights[i], maxRight);
            NGR[i] = maxRight;
        }
        
        int water = 0;
        // water at i = water height possible at i - height of i = min(NGL[i], NGR[i]) - heights[i]
        for(int i=0;i<n;i++){
            water += min(NGL[i], NGR[i]) - heights[i];
        }
        
        return water;
    }
};