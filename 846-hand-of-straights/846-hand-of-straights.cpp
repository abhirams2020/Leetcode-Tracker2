class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int,int> mp;
        // every element and its count is added to map
        // map used since we want to start with smallest number
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        // check if all elements can be grouped
        while(!mp.size()==0){
            int start = (*mp.begin()).first;
            // try to create group starting with smallest in map
            for(int k=0;k<groupSize;k++){
                // if group cannot be formed, return false
                if(!mp.count(start+k)){
                    return false;
                }
                // if group can be form, reduce 1 from count of mp[start+k]
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