class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> qq;
        int vis[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    qq.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!qq.empty()){
            int nrow=qq.front().first.first;
            int ncol=qq.front().first.second;
            int t=qq.front().second;

            tm=max(tm,t);
            qq.pop();
            for(int i=0;i<4;i++){
                int r=nrow+drow[i];
                int c=ncol+dcol[i];

                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]!=2 && grid[r][c]==1){
                    qq.push({{r,c},t+1});
                    vis[r][c]=2;
                }

            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return tm;


    }
};