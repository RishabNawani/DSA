class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        queue<pair<int,int>> qq; // ((row,col))
        int hh=image[sr][sc];
        if(color==hh) return image;


    
        qq.push({sr,sc});
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};// up , right, down, left
        int dcol[]={0,1,0,-1};// up , right, down, left

        while(!qq.empty()){
            int nrow=qq.front().first;// the current row
            int ncol=qq.front().second;// current column

            qq.pop();
            for(int i=0;i<4;i++){
                int r=nrow+drow[i];
                int c=ncol+dcol[i];

                if(r>=0 && r<n && c>=0 && c<m && image[r][c]==hh){
                    image[r][c]=color;
                    qq.push({r,c});
                }
            }

        }

        return image;



    }
};