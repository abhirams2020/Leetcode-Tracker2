class Solution {
public:
    using pii = pair<int,int>;
    
    vector<pii> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // N,E,S,W
    
    pii goStraight(pii currPos, int currDir){
        int curr_x = currPos.first;
        int curr_y = currPos.second;
        curr_x += 2*dir[currDir].first;
        curr_y += 2*dir[currDir].second;
        return {curr_x, curr_y};
    }
    
    int turnLeft(int currDir){
        if(currDir==0){
            return 3;
        }
        currDir = (currDir-1)%4;
        return currDir;
    }
    
    int turnRight(int currDir){
        currDir = (currDir+1)%4;
        return currDir;
    }
    
    bool isRobotBounded(string instructions) {
        pii startPos = {0,0};
        pii currPos = startPos;
        int currDir = 0;
        for(auto i:instructions){
            if(i=='G'){
                currPos = goStraight(currPos, currDir);
            }
            else if(i=='L'){
                currDir = turnLeft(currDir);
            }
            else if(i=='R'){
                currDir = turnRight(currDir);
            }
        }
        return (startPos==currPos) || (currDir!=0);
    }
};