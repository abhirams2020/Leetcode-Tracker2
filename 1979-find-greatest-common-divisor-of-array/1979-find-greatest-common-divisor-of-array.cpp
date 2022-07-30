class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        for(auto i:nums){
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return gcd(mx,mn);
    }
};