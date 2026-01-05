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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */