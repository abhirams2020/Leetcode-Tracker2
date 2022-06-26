class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        while(!s.empty()){
            int len = 1;
            int num = *s.begin();
            s.erase(num);
            int left=num-1, right=num+1;
            while(s.count(left)){
                s.erase(left);
                left--;
                len++;
            }
            while(s.count(right)){
                s.erase(right);
                right++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};