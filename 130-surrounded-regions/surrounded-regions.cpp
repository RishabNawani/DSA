class Solution {
public:
/*
mark all the boundary O as safe first i.e. all O which are present at the boundary are the source of our multi source BFS , and all the O which are connected to these boundary O are also marked as safe and pushed into the queue. These O are marked as T , which is used to indicate these are safe. The rest of the O are still marked O ( which arent connected to the boundary O). Now , these non safe O are then marked as X later on and the T are marked as O.
*/
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> qq; // ((row,col))
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') qq.push({i,0});
            if(board[i][m-1]=='O')qq.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') qq.push({0,i});
            if(board[n-1][i]=='O')qq.push({n-1,i});
        }
        int drow[]={-1,0,1,0};// up , right, down, left
        int dcol[]={0,1,0,-1};// up , right, down, left
        while(!qq.empty()){
            int nrow=qq.front().first;
            int ncol=qq.front().second;
            qq.pop();
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || board[nrow][ncol]!='O'){
                continue;
            }
            board[nrow][ncol]='T'; 
            for(int i=0;i<4;i++){
                int r=nrow+drow[i];
                int c=ncol+dcol[i];
                qq.push({r,c});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};