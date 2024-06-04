class Twitter {
public:
    unordered_map<int,unordered_set<int>> ds;
    vector<pair<int,int>> posts;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;

        int count = 1;
        for(int i = posts.size() - 1; i >= 0 && count <= 10; i--){
            int Post_UserId = posts[i].second;
            int post_Id = posts[i].first;
            if(Post_UserId == userId || ds[userId].find(Post_UserId) != ds[userId].end()){
                ans.push_back(post_Id);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        ds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        ds[followerId].erase(followeeId);
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
