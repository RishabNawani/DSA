class Solution {
public:
    int f(int ind,vector<int>& arr,int k,vector<int>& dp){
        int n=arr.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len=0;
        int maxx=INT_MIN;
        int maxans=INT_MIN;

        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxx=max(maxx,arr[j]);
            int sum=len*maxx+f(j+1,arr,k,dp);
            maxans=max(maxans,sum);

        }

        return dp[ind]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //vector<int> dp(n,-1);

        //return f(0,arr,k,dp);
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int len=0;
            int maxx=INT_MIN;
            int maxans=INT_MIN;

            for(int j=ind;j<min(ind+k,n);j++){
                len++;
                maxx=max(maxx,arr[j]);
                int sum=len*maxx+dp[j+1];
                maxans=max(maxans,sum);

            }

            dp[ind]=maxans;
        }

        return dp[0];
    }
};