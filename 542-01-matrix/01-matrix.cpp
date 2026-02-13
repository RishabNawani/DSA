class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>> qq; // ((row,col))
/// to mark all the already rotten oranges and mark the not rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    qq.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }



    
        int drow[]={-1,0,1,0};// up , right, down, left
        int dcol[]={0,1,0,-1};// up , right, down, left

        while(!qq.empty()){
            int nrow=qq.front().first;// the current row
            int ncol=qq.front().second;// current column

            qq.pop();
            for(int i=0;i<4;i++){
                int r=nrow+drow[i];
                int c=ncol+dcol[i];

                if(r>=0 && r<n && c>=0 && c<m && mat[r][c]==-1){
                    mat[r][c]=mat[nrow][ncol]+1;
                    qq.push({r,c});
                }
            }

        }

        return mat;

    }
};