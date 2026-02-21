class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
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
                            qq.push({r,c});
                        }
                    }

                    cnt++;
                }
            }
        }
        return cnt;
    }
};