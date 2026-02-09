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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjj(v);

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjj[i].push_back(j);
                    adjj[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adjj,vis,i);
            }
        }

        return cnt;
    }
};