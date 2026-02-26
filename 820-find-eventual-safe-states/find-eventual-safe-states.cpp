class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>> adjj(v);
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: graph[i]){
                adjj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> qq;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                qq.push(i);
            }
        }
        vector<int> safee;
        while(!qq.empty()){
            int node=qq.front();
            qq.pop();
            safee.push_back(node);
            for(auto it: adjj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    qq.push(it);
                }
            }

        }
        sort(safee.begin(),safee.end());
        return safee;
    }
};