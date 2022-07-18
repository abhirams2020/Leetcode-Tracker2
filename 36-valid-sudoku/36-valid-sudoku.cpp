class Solution {
public:
    
    int dpRow[9];
    int dpCol[9];
    int dpGrid[3][3];
    
    bool checkValid(vector<vector<char>> &board, int row ,int col){
        int n = board.size();
        
        // check row
        if(dpRow[row]!=-1){
            if(dpRow[row]==false){
                return false;
            }
        }
        else {
            unordered_set<char> rowSet;
            for(int j=0;j<n;j++){
                if(board[row][j]!='.'){
                    if(rowSet.count(board[row][j])){
                        return dpRow[row] = false;
                    }
                    rowSet.insert(board[row][j]);
                }
            }
            dpRow[row] = true;
        }
        
        // check col
        if(dpCol[col]!=-1){
            if(dpCol[col]==false){
                return false;
            }
        }
        else {
            unordered_set<char> colSet;
            for(int i=0;i<n;i++){
                if(board[i][col]!='.'){
                    if(colSet.count(board[i][col])){
                        return dpCol[col] = false;
                    }
                    colSet.insert(board[i][col]);
                }
            }
            dpCol[col] = true;
        }
        
        // check sub box
        int gridRowIdx = row/3;
        int gridColIdx = col/3;
        if(dpGrid[gridRowIdx][gridColIdx] != -1){
            if(dpGrid[gridRowIdx][gridColIdx] == false){
                return false;
            }
        }
        else {
            unordered_set<char> gridSet;
            int subRow = 3*(row/3);
            int subCol = 3*(col/3);

            for(int i=subRow;i<subRow+3;i++){
                for(int j=subCol;j<subCol+3;j++){
                    if(board[i][j]!='.'){
                        if(gridSet.count(board[i][j])){
                            return dpGrid[gridRowIdx][gridColIdx] = false;
                        }
                        gridSet.insert(board[i][j]);
                    }
                }
            }
            dpGrid[gridRowIdx][gridColIdx] = true;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(dpRow,-1,sizeof(dpRow));
        memset(dpCol,-1,sizeof(dpCol));
        memset(dpGrid,-1,sizeof(dpGrid));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(checkValid(board,i,j)==false){
                    return false;
                }
            }
        }
        return true;
    }
};