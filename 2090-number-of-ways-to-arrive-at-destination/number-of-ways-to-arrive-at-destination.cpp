class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]}); /// constructing the graph from the vector
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX); /// stores shortest time to reach i
        vector<long long> ways(n, 0); /// stores the number of ways to reach it

        priority_queue<
            pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<>
        > pq; ///{time,node}

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop(); /// the node with the smallest time

            if (time > dist[node]) continue; /// if for a node , a better path was found , then skip it.

            for (auto &[next, wt] : adj[node]) {
                long long newTime = time + wt; /// update time

                if (newTime < dist[next]) { // only if the time is less than previously stored
                    dist[next] = newTime;
                    ways[next] = ways[node]; // copy all the ways from previous node to current as all the previous ways will also pass through the next node as well
                    pq.push({newTime, next});
                }
                else if (newTime == dist[next]) {// if equal time
                    ways[next] = (ways[next] + ways[node]) % MOD; /// add the previous nodes to next as well to update it
                }
            }
        }

        return ways[n - 1];/// the final next is n-1 , so all the ways get stored at the end 
    }
};