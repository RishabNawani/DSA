class Solution {
public:

/// approach 1 code not here but it showed that we create two vectors, one right and one left , traverse through
/// the ratings array from l to r and r to l respectively for left and right , then take max value at the same index
/// from both arrays , add it to the sum and return the sum.


///approach 2
    int candy(vector<int>& ratings) {

        int n=ratings.size();
        vector<int> leftt(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                leftt[i]=leftt[i-1]+1;
            }
        }

        int summ=0;
        summ+=leftt[n-1];
        int curr=1;
        int right=1;


    
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr=right+1;
                right=curr;
            }

            else{
                curr=1;
                right=1;
            }

            summ+=max(leftt[i],curr);
        }


        return summ;

    }
};