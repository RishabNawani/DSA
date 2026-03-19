class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distt(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++) distt[i][i]=0;
        for(auto &it :edges){
            distt[it[0]][it[1]]=it[2];
            distt[it[1]][it[0]]=it[2];
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    distt[i][j] = min(distt[i][j], distt[i][k] + distt[k][j]);
                }
            }
        }

        int city=-1;
        int minreach=INT_MAX;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && distt[i][j]<=distanceThreshold){
                    count++;
                }
            }

            if(count<=minreach){
                minreach=count;
                city=i;
            }
        }

        return city;

    }
};