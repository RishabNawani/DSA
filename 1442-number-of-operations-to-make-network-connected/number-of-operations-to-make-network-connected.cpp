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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adjj(n);
        for(auto &it:connections){
            adjj[it[0]].push_back(it[1]);
            adjj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        vector<int> viss(n,0);
        for(int i=0;i<n;i++){
            if(viss[i]==0){
                cnt++;
                dfs(adjj,viss,i);
            }
        }
    

        return cnt-1;
    }
};