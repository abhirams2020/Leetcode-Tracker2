class Solution {
public:
    bool isEvenDigits(int n){
        int count = 0;
        while(n>0){
            n = n/10;
            count++;
        }
        return count % 2 == 0;
    }
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto &i:nums){
            if(isEvenDigits(i)){
                count++;
            }
        }
        return count;
    }
};