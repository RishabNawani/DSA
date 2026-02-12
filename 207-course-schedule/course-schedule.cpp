class Solution {
public:
    bool dfs(vector<vector<int>>& adjj,vector<int>& viss, int i){
        if(viss[i]==1) return true;
        if(viss[i]==2) return false;
        viss[i]=1;
        for(int neigh:adjj[i]){
            if(dfs(adjj,viss,neigh)) return true;
        }

        viss[i]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjj(numCourses);

        for(auto &p: prerequisites){
            int b=p[0];
            int a=p[1];

            adjj[a].push_back(b);
        }

        vector<int> viss(numCourses,0);


        for(int i=0;i<numCourses;i++){
            if(viss[i]==0){
                if(dfs(adjj,viss,i)) return false;
            }
        }

        return true;


    }
};