class Solution {
public:
/*
    bool binarrryy(vector<int>& matrix, int target){
        int n=matrix.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid]==target) return true;
            else if(matrix[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
*/   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        int n=matrix.size();
        for(int i=0; i<n; i++){
            bool checkk =binarrryy(matrix[i],target);
            if(checkk) return true;
        }
        return false;
        */
      
        int n=matrix.size();
        int m=matrix[0].size();
        /*
        int row=0, col=m-1;
        while(row<n&& col>=0){
           if(matrix[row][col]==target) return true;
           if(matrix[row][col]<target) row++;
           else col--;
        } 
        return false;  
        */

        int r=n-1, c=0;
        while(r>=0 && c<m){
            if(matrix[r][c]==target) return true;
            if(matrix[r][c]>target) r--;
            else c++;
        }
        return false;
    }
};