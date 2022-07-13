/*
// BRUTE FORCE APPROACH BY BACKTRACKING
class Solution {
public:
    // count rows where all values in a row is same
    int countEqualRows(vector<vector<int>> &matrix){
        int count = 0;
        for(int i=0;i<matrix.size();i++){
            int curr = matrix[i][0];
            bool isSame = true;
            // the row should be all 0 or all 1. 1 to n-1 elements should have value = nums[i][0]
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]!=curr){
                    isSame = false;
                }
            }
            if(isSame==true){
                count++;
            }
        }
        return count;
    }
    
    // flip elements in i'th index column. 0 becomes 1 and 1 becomes 0.
    void flipCol(vector<vector<int>> &matrix, int j){
        for(int i=0;i<matrix.size();i++){
            matrix[i][j] = 1-matrix[i][j];
        }
    }
    
    int solve(vector<vector<int>>& matrix, int j){
        if(j==matrix[0].size()){
            return countEqualRows(matrix);
        }
        int notFlip = solve(matrix,j+1);
        flipCol(matrix,j);
        int flip = solve(matrix,j+1);
        flipCol(matrix,j);
        return max(flip, notFlip);
    }
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        return solve(matrix,0);
    }
};
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        for(int i=0;i<matrix.size();i++){
            int first = matrix[i][0];
            int j = 1;
            string temp = "T";
            // for each row, find the pattern of the row. eg. 100100 and 011011 have same pattern
            // only rows with same pattern will be counted when flipped. pattern = TFFTFF
            // number == first num will be T, otherwise it is F.
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==first){
                    temp.push_back('T');
                }
                else {
                    temp.push_back('F');
                }
            }
            mp[temp]++;
        }
        int maxCount = 0;
        for(auto [k,v]:mp){
            maxCount = max(maxCount, v);
        }
        return maxCount;
    }
};