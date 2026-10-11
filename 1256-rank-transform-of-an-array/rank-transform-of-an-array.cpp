class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> ranking;
        vector<int> rankk(arr);
        sort(rankk.begin(),rankk.end());
        int r=1;
        for(int i=0;i<arr.size();i++){
            if(i>0 && rankk[i]>rankk[i-1]){
                r++;
            }
            ranking[rankk[i]]=r;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=ranking[arr[i]];
        }

        return arr;
    }
};