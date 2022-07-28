class Solution {
public:
    // ROLLING HASH USING DEQUE. ADD TO RIGHT AND REMOVE FROM LEFT.
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length() < needle.length()){
            return -1;
        }
        int n = needle.size();
        deque<char> needleQ;
        for(auto c:needle){
            needleQ.push_back(c);
        }
        deque<char> currQ;
        for(int i=0;i<n;i++){
            currQ.push_back(haystack[i]);
        }
        for(int i=0;i<haystack.size()-n+1;i++){
            if(currQ == needleQ){
                return i;
            }
            currQ.pop_front();
            currQ.push_back(haystack[i+n]);
        }
        return -1;
    }
};