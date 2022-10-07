class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()){
            return ans;
        }
        unordered_map<char,int> mp1, mp2;
        for(auto ch:p){
            mp2[ch]++;
        }
        int l = 0;
        for(int r=0;r<s.size();r++){
            mp1[s[r]]++;
            if(r-l+1 == p.size()){
                if(mp1 == mp2){
                    ans.push_back(l);
                }
                mp1[s[l]]--;
                if(mp1[s[l]]==0){
                    mp1.erase(s[l]);
                }
                l++;
            }
        }
        return ans;
    }
};