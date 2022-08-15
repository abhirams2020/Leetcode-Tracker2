class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        
        vector<vector<char>> matrix(numRows, vector<char> (s.length(), '#')); // fill with # to show empty spaces
        
        vector<vector<int>> directions = {{1,0}, {-1,1}}; // down direction and northeast diagonal direction
        
        int currR = 0, currC = 0;
        
        int dir = 0;
        
        int i = 0;
        
        while(i<s.length()){
            matrix[currR][currC] = s[i];
            if(currR == numRows-1){
                dir = 1;
            }
            else if(currR == 0){
                dir = 0;
            }
            currR = currR + directions[dir][0];
            currC = currC + directions[dir][1];
            i++;
        }
        
        string ans;
        
        // read the matrix row by row and add non empty (not #) elements to ans
        for(auto &v:matrix){
            for(auto &i:v){
                if(i!='#'){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};