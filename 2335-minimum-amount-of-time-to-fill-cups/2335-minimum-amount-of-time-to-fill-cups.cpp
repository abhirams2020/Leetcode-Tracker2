class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    
    int fillCups(vector<int>& amount) {
        int t = 0;
        sort(amount.begin(),amount.end(),cmp);
        while(amount[0]!=0 && (amount[1]>0 || amount[2]>0)){
            if(amount[1]>0 && amount[0]>0){
                amount[0]--;
                amount[1]--;
                t++;
            }
            else if(amount[2]>0 && amount[0]>0){
                amount[0]--;
                amount[2]--;
                t++;
            }
            sort(amount.begin(),amount.end(),cmp);
        }
        return t+amount[0];
    }
};