class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });

        int lastt=intervals[0][1];

        int cnt=0;

        for(int i=1;i<n;i++){
            if(lastt>intervals[i][0]){
                cnt++;
            }
            else{
                lastt=intervals[i][1];
            }
        }

        return cnt;
        /*
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastt){
                cnt++;
                lastt=intervals[i][1];
            }
        }

        return n-cnt;
        */
    }
};