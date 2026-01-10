class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ress;

        int i=0;
        int n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0]){
            ress.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }

        ress.push_back(newInterval);

        while(i<n){
            ress.push_back(intervals[i]);
            i++;
        }

        return ress;




        /*
the mistakes in my code->( my approach was correct , just had some mistakes in it )

erase(end()) is invalid — end() points past the last element.

This causes undefined behavior / crash.

You erase newInterval after inserting it once

But later logic may still need it

Also, removing only two elements is meaningless — interval has exactly two elements

If newInterval[0] is greater than all interval starts, your loop ends without ever pushing newInterval.


and infinite loop risk too.



        vector<vector<int>> anss;
        int n=intervals.size();
        int i=0;

        while(i<n){
            if(newInterval.empty() || intervals[i][0]<newInterval[0]){
                anss.push_back(intervals[i]);
                i++;
            }

            else{
                anss.push_back(newInterval);
                newInterval.erase(newInterval.begin());
                newInterval.erase(newInterval.end());
            }
        }
        vector<vector<int>> ans;
        for(int j=0; j<anss.size() ; j++){
            if(ans.empty() || anss[j][0]>ans.back()[1]){
                ans.push_back(anss[j]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],anss[j][1]);
            }
        }
        return ans;
*/

/*
        vector<vector<int>> anss;
        int n = intervals.size();
        int i = 0;
        bool inserted = false;

        // Step 1: Insert newInterval at correct position
        while(i<n){
            if (!inserted && intervals[i][0] >= newInterval[0]) {
                anss.push_back(newInterval);
                inserted = true;
            }
            anss.push_back(intervals[i]);
            i++;
        }

        // If newInterval was never inserted
        if (!inserted) {
            anss.push_back(newInterval);
        }

        // Step 2: Merge intervals
        vector<vector<int>> ans;
        for (int j = 0; j < anss.size(); j++) {
            if (ans.empty() || anss[j][0] > ans.back()[1]) {
                ans.push_back(anss[j]);
            } else {
                ans.back()[1] = max(ans.back()[1], anss[j][1]);
            }
        }

        return ans;
        */

    }
};