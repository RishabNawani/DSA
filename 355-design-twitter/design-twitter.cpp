/*
Each user’s tweets are stored in reverse chronological order

Each tweet has a timestamp

getNewsFeed uses a max-heap to merge only the latest tweets

We never sort all tweets

We stop after collecting 10 tweets
*/
class Twitter {
public:
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timeStamp;

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // Max heap: {time, tweetId, userId, index_in_user_tweets}
        priority_queue<tuple<int,int,int,int>> pq;

        // Add user's own latest tweet
        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first,
                     tweets[userId][idx].second,
                     userId,
                     idx});
        }

        // Add followees' latest tweets
        for (int f : followees[userId]) {
            if (!tweets[f].empty()) {
                int idx = tweets[f].size() - 1;
                pq.push({tweets[f][idx].first,
                         tweets[f][idx].second,
                         f,
                         idx});
            }
        }

        // Get top 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {
            auto [time, tweetId, uid, idx] = pq.top();
            pq.pop();

            result.push_back(tweetId);

            // Push next older tweet from same user
            if (idx > 0) {
                idx--;
                pq.push({tweets[uid][idx].first,
                         tweets[uid][idx].second,
                         uid,
                         idx});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/*
class Twitter {
public:
    Twitter() {
        
    }
    
    map<int , vector<int>> followw;
    map<int , vector<pair<int,int>>> newss;
    int timer=0;
    void postTweet(int userId, int tweetId) {
        newss[userId].push_back({timer++,tweetId});   
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> neww;
        for(int t : followw[userId]){
            for(auto f : newss[t]){
                neww.push_back(f);
                
            }   
        }

        for(auto id : newss[userId]){
            neww.push_back(id);
        }

        sort(neww.begin(),neww.end(),[](auto &a , auto &b){
            return a.first>b.first;
        });
        vector<int> feed;

        for(int i=0;i<neww.size()&& i<10;i++){
            feed.push_back(neww[i].second);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return ;
        for(int x: followw[followerId]){
            if(x==followeeId) return;
        }
        followw[followerId].push_back(followeeId);

    } 
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return ;
        else{
            for(int i=0;i<followw[followerId].size();i++){
                if(followw[followerId][i]==followeeId){
                    followw[followerId].erase(followw[followerId].begin()+i);
                    break;
                }
            }
        }
    }

};
*/

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */