/*
class Solution {
public:
    // O(m*n) space and O(m*n) time
    // Find triplets which are less than or equal to target since only they can give target on combining
    // If triplet value > target values, answer will not be obtained
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxX=target[0], maxY=target[1], maxZ=target[2];
        
        vector<vector<int>> validTriplets;
        
        for(int i=0;i<triplets.size();i++){
            // for each vector check if its values are <= target values
            int count = 0;
            for(int j=0; j<triplets[i].size(); j++){
                if(triplets[i][j]<=target[j]){
                    count++;
                }
            }
            if(count==target.size()){
                validTriplets.push_back(triplets[i]);
            }
        }
        // from valid triplets, find max at each position and assign to maxTriplet
        vector<int> maxTriplet(target.size(), 0);
        
        for(int i=0;i<validTriplets.size();i++){
            for(int j=0;j<validTriplets[0].size();j++){
                maxTriplet[j] = max(maxTriplet[j], validTriplets[i][j]);
            }
        }
        
        return maxTriplet==target;
    }
};
*/

/*
class Solution {
public:
    // O(1) space and O(m*n) time
    // Find triplets which are less than or equal to target since only they can give target on combining
    // If triplet value > target values, answer will not be obtained
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxX=target[0], maxY=target[1], maxZ=target[2];

        // from valid triplets, find max at each position and assign to maxTriplet
        vector<int> maxTriplet(target.size(), 0);
        
        for(int i=0;i<triplets.size();i++){
            // for each vector check if its values are <= target values
            int count = 0;
            for(int j=0; j<triplets[i].size(); j++){
                if(triplets[i][j]<=target[j]){
                    count++;
                }
            }
            
            // if count==target.size() means all members are <= corresponding members in target
            if(count==target.size()){
                for(int j=0;j<triplets[i].size(); j++){
                    maxTriplet[j] = max(maxTriplet[j], triplets[i][j]);
                }
                // after every updation of maxTriplet, check if target has been obtained
                if(maxTriplet==target){
                    return true;
                }
            }
        }
        
        return maxTriplet==target;
    }
};
*/

class Solution {
public:
    // O(1) space and O(m*n) time
    // Find triplets which are less than or equal to target since only they can give target on combining
    // If triplet value > target values, answer will not be obtained
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first=false, second=false, third=false;
        
        for(auto t:triplets){
            if(t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]){
                first = first || (t[0]==target[0]);
                second = second || (t[1]==target[1]);
                third = third || (t[2]==target[2]);
            }
        }
        
        return first && second && third;
    }
};