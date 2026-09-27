/**
 * LeetCode 355: Design Twitter
 * Time Complexity: getNewsFeed O(F log F), post/follow/unfollow O(1)
 * Space Complexity: O(Users + Tweets)
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
    int timeStamp = 0;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets; // userId -> {time, tweetId}
    std::unordered_map<int, std::unordered_set<int>> followees;      // userId -> followeeIds
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        auto pushUserTweets = [&](int u) {
            for (const auto& t : tweets[u]) maxHeap.push(t);
        };
        pushUserTweets(userId);
        for (int f : followees[userId]) pushUserTweets(f);

        std::vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
