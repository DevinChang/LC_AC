typedef pair<int, int> PII;
#define x first
#define y second

class Twitter {
public:
    unordered_map<int, vector<PII>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int ts;
    /** Initialize your data structure here. */
    Twitter(): ts(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts, tweetId});
        ts++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int u) {
        priority_queue<vector<int>> heap;
        // 将自己作为一个粉丝
        follows[u].insert(u);
        for(auto user : follows[u]) {
            auto &ts = tweets[user];
            if(ts.size()) {
                int i = ts.size() - 1; // 从最近的时间开始入堆
                heap.push({ts[i].x, ts[i].y, i, user});
            }
        }
        vector<int> res;
        for(int i = 0; i < 10 && heap.size(); i++) {
            auto t = heap.top();
            heap.pop();
            res.push_back(t[1]);
            // 将出堆的那个推特列表的下一位入堆，多路排序
            int j = t[2];
            if(j) {
                j--;
                int user = t[3];
                auto &ts = tweets[user];
                heap.push({ts[j].x, ts[j].y, j, user});
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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