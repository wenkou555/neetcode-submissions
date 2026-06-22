class Twitter {
public:
    Twitter() {
        tweetCount = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweet[userId].push_back({tweetCount, tweetId});
        tweetCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> tweetQueue;

        userFollow[userId].insert(userId);
        vector<int> followVector(userFollow[userId].begin(), userFollow[userId].end());

        for(auto& follow: followVector) {
            if (userTweet.find(follow) == userTweet.end()) {
                continue;
            }
            int targetTweetCount = 0;
            int vectorIndex = userTweet[follow].size() - 1;
            while (targetTweetCount < 10 && vectorIndex >= 0) {
                tweetQueue.push(userTweet[follow][vectorIndex]);
                vectorIndex--;
                targetTweetCount++;
            }
        }

        vector<int> newsFeed;
        int tweetRemaining = 10;
        while (tweetRemaining != 0 && !tweetQueue.empty()) {
            newsFeed.push_back(tweetQueue.top().second);
            tweetQueue.pop();
            tweetRemaining--;
        }

        return newsFeed;
        
    }
    
    void follow(int followerId, int followeeId) {
        userFollow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollow[followerId].erase(followeeId);
    }
private:
    unordered_map<int, vector<pair<int, int>>> userTweet;
    unordered_map<int, unordered_set<int>> userFollow;
    int tweetCount;
};
