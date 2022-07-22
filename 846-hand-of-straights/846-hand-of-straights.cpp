class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(!mp.size()==0){
            int start = (*mp.begin()).first;
            for(int k=0;k<groupSize;k++){
                if(!mp.count(start+k)){
                    return false;
                }
                else {
                    mp[start+k]--;
                    if(mp[start+k]==0){
                        mp.erase(start+k);
                    }
                }
            }
        }
        return true;
    }
};