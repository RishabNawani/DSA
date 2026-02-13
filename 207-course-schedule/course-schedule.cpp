class Solution {
public:
    bool dfs(vector<vector<int>>& adjj,vector<int>& viss, int i){
        /*
        if(viss[i]==1) return true;
        if(viss[i]==2) return false;
        viss[i]=1;
        for(int neigh:adjj[i]){
            if(dfs(adjj,viss,neigh)) return true;
        }

        viss[i]=2;
        return false;
        */
        viss[i]=1;
        for(auto adj:adjj[i]){
            if(!viss[adj]){
                if(dfs(adjj,viss,adj)) return true; /// here this approach fails because we use the parent appraoch which will work in undirected but not in directed and here the graph is directed graph.
            }
            else if(viss[adj]==1) return true;
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
            if(!viss[i]){
                if(dfs(adjj,viss,i)==true) return false;
            }
        }

        return true;
    }
};