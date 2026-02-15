class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> qq; // ((row,col))
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) qq.push({i,0});
            if(grid[i][m-1]==1)qq.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) qq.push({0,i});
            if(grid[n-1][i]==1)qq.push({n-1,i});
        }
        int drow[]={-1,0,1,0};// up , right, down, left
        int dcol[]={0,1,0,-1};// up , right, down, left
        while(!qq.empty()){
            int nrow=qq.front().first;
            int ncol=qq.front().second;
            qq.pop();
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]!=1){
                continue;
            }
            grid[nrow][ncol]=-1; 
            for(int i=0;i<4;i++){
                int r=nrow+drow[i];
                int c=ncol+dcol[i];
                qq.push({r,c});
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
    
            }
        }
        return cnt;
    }
};