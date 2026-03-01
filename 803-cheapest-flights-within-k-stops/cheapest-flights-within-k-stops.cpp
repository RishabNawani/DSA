class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        int l=flights[0].size();
        queue<pair<int,pair<int,int>>> qq;
        vector<pair<int,int>> adjj[n];
        for(auto it: flights){
            adjj[it[0]].push_back({it[1],it[2]});
        }

        qq.push({0,{src,0}}); // {stops, {nodes , dist}}

        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!qq.empty()){
            int st=qq.front().first;
            int s=qq.front().second.first;
            int p=qq.front().second.second;
            qq.pop();

            if(st>k) continue;
            for(auto it:adjj[s]){
                int nn=it.first;
                int pr=it.second;

                if(p+pr<dist[nn] && st<=k){
                    dist[nn]=p+pr;
                    qq.push({st+1,{nn,p+pr}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};