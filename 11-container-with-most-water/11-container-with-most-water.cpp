class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int maxWater = 0;
        // 2 pointer approach - start from ends and move the smaller height index
        // heights bw 2 index = min(height[l],height[r]) * (r - l)
        while(l<r){
            int currWater = min(height[l], height[r]) * (r - l);
            maxWater = max(maxWater, currWater);
            if(height[l]<height[r]) {
                l++;
            }
            else if(height[l]>=height[r]){
                r--;
            }
            else { // heights[l]==heights[r]
                l++;
                r--;
            }
        }
        return maxWater;
    }
};