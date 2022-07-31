class Solution {
public:
    using pdd = pair<double,double>;
    
    struct cmp {
        bool operator() (pdd &x, pdd &y) {
            // delta measures how much we change average if we add 1 to numerator and denominator
            double del_x = ( ((x.first+1)/(x.second+1)) - (x.first/x.second) );
            double del_y = ( ((y.first+1)/(y.second+1)) - (y.first/y.second) );
            return del_x < del_y;
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdd, vector<pdd>, cmp> pq;
        for(auto it:classes){
            pq.push({(double)it[0], (double)it[1]});
        }
        // each time add 1 brilliant student to any class
        while(extraStudents>0){
            auto it = pq.top();
            pq.pop();
            double a=it.first, b=it.second;
            pq.push({it.first+1, it.second+1});
            extraStudents--;
        }
        // find maximum average possible after adding all extra students
        double sum = 0;
        int count = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double a=it.first, b=it.second;
            sum += (a/b);
            count++;
        }
        double new_average = sum / count;
        return new_average;
    }
};