//Q4: Design Twitter
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for (auto &t : tweets[userId]) pq.push(t);

        for (int f : follows[userId]) {
            for (auto &t : tweets[f]) pq.push(t);
        }

        vector<int> res;
        int cnt = 10;

        while (!pq.empty() && cnt--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter obj;
    obj.postTweet(1, 5);
    vector<int> feed = obj.getNewsFeed(1);

    for (int x : feed) cout << x << " ";
}

//ANS:=
//5