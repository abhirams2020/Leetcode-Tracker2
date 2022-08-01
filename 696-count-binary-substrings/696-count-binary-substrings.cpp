class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int count = 0;
        // similar to count consecutive elements
        // when we find 0,1 consecutive expand to left and right to get max possible substring
        // for each valid substring increment count
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                int left = s[i], right = s[i+1];
                int l = i, r = i+1;
                while(l>=0 && r<n && s[l]==left && s[r]==right){
                    count++;
                    l--;
                    r++;
                }
            }
        }
        return count;
    }
};