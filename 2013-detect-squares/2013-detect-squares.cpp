class DetectSquares {
public:
    map<pair<int,int>,int> mp;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0], y1 = point[1];
        for(auto i:mp){
            int x2 = i.first.first, y2 = i.first.second;
            // we consider current point as a diagonal. for a square diagonal, x1-x2 = y1-y2
            // if diagonal pts are (x1,y1) & (x2,y2), other points should be (x1,y2) & (x2,y1)
            
            // dont consider same point as valid diagonal
            if(x1==x2 && y1==y2){
                continue;
            }
            if(abs(x1-x2)==abs(y1-y2) && mp.count({x1,y2}) && mp.count({x2,y1})){
                int c1 = mp[{x2,y2}];
                int c2 = mp[{x1,y2}];
                int c3 = mp[{x2,y1}];
                // total no of possible squares is 1 * pt1_count * pt2_count * pt3_count
                ans += c1*c2*c3;
            }
        }
        return ans;
    }
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */