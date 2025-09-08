class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> user_tweets_map;
    unordered_map<int,unordered_set<int>> follower_followee_map;
    int timestamp;
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        user_tweets_map[userId].push_back({timestamp,tweetId});
        timestamp++;
    }

    vector<int> getNewsFeed(int userId) {
        //get the top 10 recent tweets of all ppl who this user follow
        priority_queue <pair<int,int>> tweets;
        for(auto& usr:follower_followee_map[userId]){
            for(auto& tweet:user_tweets_map[usr]){
                tweets.push(tweet);
            }
        }
        for(auto& tweet: user_tweets_map[userId]){
             tweets.push(tweet);
        }
        vector<int> top10;
        int count = 10;
        while(!tweets.empty() and count--){
            top10.push_back(tweets.top().second);
            tweets.pop();
        }
        return top10;

    }
    void follow(int followerId, int followeeId) {
        follower_followee_map[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {   
        follower_followee_map[followerId].erase(followeeId);
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
