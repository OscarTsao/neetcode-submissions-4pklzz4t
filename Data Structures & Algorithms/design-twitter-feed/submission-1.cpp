class Twitter {
private:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> posts;
    int globalTime = 0;

public:
    Twitter() {
        globalTime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        globalTime++;
        posts[userId].push_back({globalTime, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> maxHeap;

        if (!posts[userId].empty()) {
            int index = posts[userId].size() - 1;
            int postId = posts[userId][index].second;
            int postTime = posts[userId][index].first;
            maxHeap.push({postTime, postId, index, userId});
        }

        for (int followee : followers[userId]) {
            if (!posts[followee].empty()) {
                int index = posts[followee].size() - 1;
                int postId = posts[followee][index].second;
                int postTime = posts[followee][index].first;
                maxHeap.push({postTime, postId, index, followee});
            }
        }

        vector<int> results;

        while (!maxHeap.empty() && results.size() < 10) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();

            results.push_back(top[1]);

            int posterId = top[3];
            int nextIndex = top[2] - 1;

            if (nextIndex >= 0) {
                maxHeap.push({
                    posts[posterId][nextIndex].first,
                    posts[posterId][nextIndex].second,
                    nextIndex,
                    posterId
                });
            }
        }

        return results;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers.count(followerId)) {
            followers[followerId].erase(followeeId);
        }
    }
};