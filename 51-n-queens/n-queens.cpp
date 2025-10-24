class Solution {
public:
/*
    bool issafe(int row, vector<string>& board, int col, int n){
        int duprow= row;
        int dupcol=col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;

        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        col=dupcol;

        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }

        return true;
    }

    void posi(vector<string>& res,vector<vector<string>>& result,int n, int col){
        if(col==n){
            result.push_back(res);
            return;
        }

        for(int row=0;row<n; row++){
            if(issafe(row,res,col,n)){
                res[row][col]='Q';
                posi(res,result,n,col+1);
                res[row][col]='.';
            }
        }
    }

*/

    void solve(int col, int n, vector<string>& res, vector<vector<string>>& result, vector<int>& leftrow, vector<int>& upperdiag, vector<int>& lowerdiag){
        if(col==n){
            result.push_back(res);
            return;
        }

        for(int i=0; i<n;i++){
            if(leftrow[i]==0 && lowerdiag[i+col]==0 && upperdiag[n-1+col-i]==0){
                res[i][col]='Q';
                leftrow[i]=1;
                lowerdiag[i+col]=1;
                upperdiag[n-1+col-i]=1;
                solve(col+1,n,res,result,leftrow,upperdiag,lowerdiag);
                res[i][col]='.';
                leftrow[i]=0;
                lowerdiag[i+col]=0;
                upperdiag[n-1+col-i]=0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n);
        vector<vector<string>> result;
        string s(n,'.');
        for(int i=0; i<n;i++){
            res[i]=s;
        }
        vector<int> leftrow(n,0), upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        solve(0,n,res,result,leftrow,upperdiag,lowerdiag);
        /*
        posi(res,result,n,0);
        */
        return result;


    }
};