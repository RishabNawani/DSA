class Solution {
public:
    void dfs(int r, int c, int br , int bc ,vector<vector<int>> &viss,vector<vector<char>>& grid,vector<pair<int,int>> &shape){
        viss[r][c]=1;
        shape.push_back({r-br,c-bc});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];

            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !viss[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,br,bc,viss,grid,shape);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> viss(n,vector<int>(m,0));
        vector<vector<pair<int,int>>> stt;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !viss[i][j]){
                    vector<pair<int,int>> shape;
                    dfs(i,j,i,j,viss,grid,shape);
                    stt.push_back(shape);
                }
            }
        }
        return stt.size();
        /*
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> qq; // ((row,col))
        int cnt=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    qq.push({i,j});
                    while(!qq.empty()){
                        int nrow=qq.front().first;
                        int ncol=qq.front().second;
                        qq.pop();
                        if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]!='1'){
                            continue;
                        }
                        grid[nrow][ncol]='0'; 
                        for(int i=0;i<4;i++){
                            int r=nrow+drow[i];
                            int c=ncol+dcol[i];
                            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1') qq.push({r,c});
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
        */
    }
};