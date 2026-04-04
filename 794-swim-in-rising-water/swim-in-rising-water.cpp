/*
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> qq;
        qq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size();
        vector<vector<int>> viss(n,vector<int>(n,0));
        while(!qq.empty()){
            int t=qq.front().first;
            int r=qq.front().second.first;
            int c=qq.front().second.second;
            if(r==n-1 && c==n-1) return t;
            qq.pop();
            int next=INT_MAX;
            int cr=0;
            int cc=0;
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && viss[nr][nc]==0 && next>grid[nr][nc]){
                    next=grid[nr][nc];
                    cr=nr;
                    cc=nc;
                }
            }
            t=max()
            qq.push({t,{cr,cc}});
            viss[cr][cc]=1;
        }
        return 0;
    }
};
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push({grid[0][0], {0, 0}});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n - 1 && c == n - 1)
                return t;
                
            if (vis[r][c]) continue;
            vis[r][c] = 1;
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    pq.push({max(t, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        return -1;
    }
};