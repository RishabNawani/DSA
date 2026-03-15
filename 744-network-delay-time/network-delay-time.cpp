class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adjj[n+1];
        for(auto it: times){
            adjj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,INT_MAX);

        dist[k]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int time=pq.top().first;
            pq.pop();
            for(auto[nb,wt]:adjj[node]){
                if(dist[nb]>time+wt){
                    dist[nb]=time+wt;
                    pq.push({dist[nb],nb});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX?-1 : ans;

    }
};