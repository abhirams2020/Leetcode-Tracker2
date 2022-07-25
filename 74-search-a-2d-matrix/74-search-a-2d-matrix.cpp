class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from first row, last col
        int r=0, c=matrix[0].size()-1;
        // from that pos, we move only left (if curr > target) or down (if curr < target)
        while(r<matrix.size() && c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c] < target){
                r++;
            }
            else if(matrix[r][c] > target){
                c--;
            }
        }
        return false;
    }
};