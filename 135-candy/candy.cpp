class Solution {
public:

/// approach 1 code not here but it showed that we create two vectors, one right and one left , traverse through
/// the ratings array from l to r and r to l respectively for left and right , then take max value at the same index
/// from both arrays , add it to the sum and return the sum.


///approach 2
    int candy(vector<int>& ratings) {

        int n=ratings.size();

        /*
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
        */

/// approach 3 - uses slope method , it checks on two slopes , first the increasing then the decreasing , in the
/// increasing one , it looks till the peak value , till when it keeps increasing and for the decreasing value it
/// looks at the values after the peak element till it starts to remain stagnant or begans to increase again.

        int sum=1;
        int i=1;

        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }

            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }

            int down=1;

            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }

            if(down>peak){
                sum+= (down-peak);
            }
        }

        return sum;

    }
};