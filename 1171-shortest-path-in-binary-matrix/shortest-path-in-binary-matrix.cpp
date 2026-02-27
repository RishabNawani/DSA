class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>> qq;
        qq.push({{0,0},1});
        grid[0][0]=1;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dd={{1,1},{-1,-1},{1,-1},{-1,1}};
        int p=0;
        while(!qq.empty()){
            int r=qq.front().first.first;
            int c=qq.front().first.second;
            int dr=qq.front().first.first;
            int dc=qq.front().first.second;
            int pa=qq.front().second;
            p=max(p,pa);
            if(r==n-1 &&c==n-1) return p;
            qq.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                int ndr=dr+dd[i][0];
                int ndc=dc+dd[i][1];

                if(ndr>=0 && ndr<n && ndc>=0 && ndc<n && grid[ndr][ndc]==0){
                    qq.push({{ndr,ndc},pa+1});
                    grid[ndr][ndc]=1;
                }

                else if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    qq.push({{nr,nc},pa+1});
                    grid[nr][nc]=1;
                }
            }

        }
        return -1;;
    }
};