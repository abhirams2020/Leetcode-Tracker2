class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int groups = 0;
        int currLen = 1;
        while(currLen <= n){
            n -= currLen;
            currLen++;
            groups++;
        }
        return groups;
    }
}; 