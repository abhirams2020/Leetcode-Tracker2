class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> remCount;
        int count = 0;
        for(int i=0;i<time.size();i++){
            int remainder = time[i]%60;
            if(remainder==0){
                count += remCount[remainder];
            }
            if(remainder!=0 && remCount.count(60-remainder)){
                count += remCount[60-remainder];
            }
            remCount[remainder]++;
        }
        return count;
    }
};