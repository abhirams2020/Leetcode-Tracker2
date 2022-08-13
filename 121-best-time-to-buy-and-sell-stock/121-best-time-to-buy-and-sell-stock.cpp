class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minSoFar = INT_MAX;
        for(auto &i:prices){
            minSoFar = min(i, minSoFar);
            int currProf = i - minSoFar;
            maxProf = max(maxProf, currProf);
        }
        return maxProf;
    }
};