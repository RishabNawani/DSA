class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        //int cnt=0;
        int low=0, high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) high=mid-1;
            else low=mid+1;
            /*
            if(matrix[mid][0]<=target && target<=matrix[mid][m-1]){
                int l=0;
                int r=m-1;
                while(l<=r){
                    int midcol=(l+r)/2;
                    if(matrix[mid][midcol]>target) r=midcol-1;
                    else if(matrix[mid][midcol]<target) l=midcol+1;
                    else return true;
                }
                return false;
            }

            else if(matrix[mid][0]>target) high=mid-1;
            else low=mid+1;
        
            for(int j=0; j<m;j++){
                if(matrix[mid][j]<target) low =mid+1;
                else if(matrix[mid][j]>target) high=mid-1;
                else return true;
            }
            */

        }
        return false;
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target) cnt=1;
            }
        }
        if(cnt==1) return true;
        else return false;
        */
    }
};