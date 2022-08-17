class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        // when adding element remove all smaller element with opp sign
        // if larger element with opp sign found, destroy current
        for(auto &i:asteroids){
            // there can be 4 conditions. prev +ve, curr +ve | prev -ve, curr +ve | prev -ve, curr -ve | prev +ve, curr -ve
            // collision happens only when prev +ve and curr -ve
            
            // curr +ve, no need to check prev
            if(i>0){
                st.push(i);
            }
            else {
                // curr -ve and prev -ve
                if(!st.empty() && st.top()<=0){
                    st.push(i);
                }
                // curr -ve and prev +ve
                else {
                    bool isDestroyed = false;
                    while(!st.empty() && st.top() > 0){
                        // if prev_size <= curr_size and opp sign, we pop it
                        // if prev_size >= curr_size, curr is destroyed
                        if(st.top() == abs(i)){
                            st.pop();
                            isDestroyed = true;
                            break;
                        }
                        else if(st.top() > abs(i)){
                            isDestroyed = true;
                            break;
                        }
                        else {
                            st.pop();
                        }
                    }
                    if(isDestroyed == false){
                        st.push(i);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};