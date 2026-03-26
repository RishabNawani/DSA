/*class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> qq;
        int o=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) qq.push({i,j});
                else o++;
            }
        }
        int no1=0;
        int cr=0;
        int cc=0;
        if(o==0) return 1;
        if(qq.empty()) return n*n;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!qq.empty()){
            int r=qq.front().first;
            int c=qq.front().second;
            qq.pop();
            int one=0;
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1) one++;
            }
            if(one>=no1){
                no1=one;
                cr=r;
                cc=c;
            }
        }
        grid[cr][cc]=1;
        qq.push({cr,cc});
        int cnt=0;
        vector<vector<int>> viss(n,vector<int>(n,0));
        while(!qq.empty()){
            int r=qq.front().first;
            int c=qq.front().second;
            qq.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && viss[nr][nc]==0 && grid[nr][nc]==1){
                    cnt++;
                    qq.push({nr,nc});
                    viss[nr][nc]=1;
                };
            }
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int n;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    int dfs(int r, int c, vector<vector<int>>& grid, int id) {
        if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
            return 0;

        grid[r][c] = id;
        int cnt = 1;

        for(int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            cnt += dfs(nr, nc, grid, id);
        }

        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> area;

        int id = 2;

        // STEP 1: Label islands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int size = dfs(i, j, grid, id);
                    area[id] = size;
                    id++;
                }
            }
        }

        int ans = 0;

        // STEP 2: Try flipping each 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int size = 1; // flip this 0

                    for(int k = 0; k < 4; k++) {
                        int ni = i + drow[k];
                        int nj = j + dcol[k];

                        if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            int islandId = grid[ni][nj];

                            if(islandId > 1 && seen.count(islandId) == 0) {
                                size += area[islandId];
                                seen.insert(islandId);
                            }
                        }
                    }

                    ans = max(ans, size);
                }
            }
        }

        // If no 0 found → full grid already
        if(ans == 0) return n * n;

        return ans;
    }
};