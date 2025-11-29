class Solution {
public:
    int lhist(int r,vector<vector<int>>& pree){
        int large=0;
        
        for(int j=0; j<pree[0].size();j++){
            if(pree[r][j]==0) continue;

            int width=pree[r][j];
            int height=0;
            for(int i=r;i>=0;i--){
                if(pree[i][j]==0) break;
                height++;
                width=min(width,pree[i][j]);
                large=max(large,height*width);
            }
        }
        return large;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> presum(m,vector<int>(n,0));
        for(int i=0; i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }
        int maxx=0;
        for(int i=0;i<presum.size();i++){
            maxx=max(maxx,lhist(i,presum));
        }

        return maxx;
    }
};