class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    
    int fillCups(vector<int>& amount) {
        int t = 0;
        sort(amount.begin(),amount.end(),cmp);
        if(amount[0]>0 && amount[1]){
            amount[0]--;
            amount[1]--;
            return 1 + fillCups(amount);
        }
        return amount[0];
    }
};