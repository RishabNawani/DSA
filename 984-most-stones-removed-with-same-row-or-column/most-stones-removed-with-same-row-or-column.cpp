class Solution {
public:
    void dfs(vector<vector<int>>& adjj,vector<int>& viss, int i){
        viss[i]=1;
        for(int it:adjj[i]){
            if(!viss[it]){
                dfs(adjj,viss,it);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1) return 0;
        int n=stones.size();
        vector<vector<int>> adjj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adjj[i].push_back(j);
                    adjj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> viss(n,0);
        for(int i=0;i<n;i++){
            if(viss[i]==0){
                cnt++;
                dfs(adjj,viss,i);
            }
        }
    

        return n-cnt;

    }
};