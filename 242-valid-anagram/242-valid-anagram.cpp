class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1, mp2;
        for(auto ch:s){
            mp1[ch]++;
        }
        for(auto ch:t){
            mp2[ch]++;
        }
        return mp1==mp2;
    }
};