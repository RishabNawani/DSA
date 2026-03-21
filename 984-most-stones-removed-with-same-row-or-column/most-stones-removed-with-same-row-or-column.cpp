class DSU {
public:
    unordered_map<int, int> parent;

    // Function to find the ultimate parent of node x
    int find(int x) {
        // If x is not present, make it its own parent
        if (parent.find(x) == parent.end())
            parent[x] = x;

        // Path compression to optimize future finds
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Function to connect two nodes
    void unite(int x, int y) {
        // Set parent of x's root to y's root
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;

        // Connect each stone's row and column (offset to avoid collision)
        for (auto& stone : stones) {
            dsu.unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;

        // Count unique connected components
        for (auto& stone : stones) {
            components.insert(dsu.find(stone[0]));
        }

        // Max stones removed = total stones - number of components
        return stones.size() - components.size();
    }
};
/*
class Diss{
        vector<int> rank , parent;
public:
    Diss(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]= findupar(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ulpu=findupar(v);
        int ulpv=findupar(v);
        if(ulpu=ulpv) return;
        if(rank[ulpu]<rank[ulpv]) parent[ulpu]=ulpv;
        else if(rank[ulpu]>rank[ulpv]) parent[ulpv]=ulpu;
        else{
            parent[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }
};
class Solution {
public:

   
    void dfs(vector<vector<int>>& adjj,vector<int>& viss, int i){
        viss[i]=1;
        for(int it:adjj[i]){
            if(!viss[it]){
                dfs(adjj,viss,it);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int maxcol=0;
        int maxrow=0;

        if(stones.size()==1) return 0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        diss(maxrow+maxcol+1);

        int n=stones.size();
        vector<vector<int>> adjj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adjj[i].push_back(j);
                    adjj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> viss(n,0);
        for(int i=0;i<n;i++){
            if(viss[i]==0){
                cnt++;
                dfs(adjj,viss,i);
            }
        }
        return n-cnt;
    }
};
*/