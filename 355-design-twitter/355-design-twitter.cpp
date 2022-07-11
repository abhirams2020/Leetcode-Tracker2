class Twitter {
public:
    int time = 0;
    priority_queue<vector<int>> posts;
    unordered_map<int, unordered_set<int>> following;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({time, userId, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        // vector<vector<int>> temp;
        set<vector<int>> temp;
        int count = 0;
        while(!posts.empty() && count<10){
            auto it = posts.top();
            if(it[1]==userId || following[userId].count(it[1])){
                ans.push_back(it[2]);
                count++;
            }
            // temp.push_back(posts.top());
            temp.insert(posts.top());
            posts.pop();
        }
        for(auto v:temp){
            posts.push(v);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].count(followeeId)){
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */