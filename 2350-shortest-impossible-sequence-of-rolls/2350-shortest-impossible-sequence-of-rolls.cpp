class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int len = 0;
        unordered_set<int> s;
        for(auto i:rolls){
            s.insert(i);
            if(s.size()==k){
                len++;
                s.clear();
            }
        }
        return len+1;
    }
};