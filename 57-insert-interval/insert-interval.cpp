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
    }
};