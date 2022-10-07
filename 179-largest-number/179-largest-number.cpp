class Solution {
public:
    static bool cmp(int &n1, int &n2){
        string s1,s2;
        s1 = to_string(n1);
        s2 = to_string(n2);
        if(s1+s2 == s2+s1){
            return false; // https://codeforces.com/blog/entry/72525
        }
        else if(s1+s2 < s2+s1){
            return false;
        }
        return true;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for(auto i:nums){
            ans += to_string(i);
        }
        // remove leading zeros
        int i0 = 0;
        while(i0<ans.size() && ans[i0]=='0'){
            i0++;
        }
        if(i0 == ans.size()){
            return "0";
        }
        ans = ans.substr(i0);
        return ans;
    }
};