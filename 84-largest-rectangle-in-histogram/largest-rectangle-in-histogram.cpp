class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        stack<int> st;
        for(int i=0; i<=n;i++){
            int h=(i==n?0:heights[i]);
            while(!st.empty() && h<heights[st.top()]){
                int hei=heights[st.top()];
                st.pop();
                int right=i;
                int left=(st.empty()?-1:st.top());
                int width=right-left-1;
                maxarea=max(maxarea,hei*width);
            }
            st.push(i);

        }
        return maxarea;
    /*
        if(heights.size()==1) return heights[0];
        vector<int> rects;
        int ind1=0;
        int ind2=0;
        for(int i=0;i<heights.size();i++){
            int maxx=heights[i];
            for(int j=i+1;j<heights.size();j++){
                maxx=max(maxx,heights[j]);
                if(!rects.empty() && maxx>rects[0]){
                    rects.pop_back();
                    rects.push_back(maxx);
                    ind1=j;
                }
                else if(rects.empty()){
                    rects.push_back(maxx);
                    ind1=j;
                }
                else{
                    continue;
                }
            }
        }
        for(int i=0;i<heights.size();i++){
            int maxx=heights[i];
            if(heights[i]==rects[0])continue;
            else{
                for(int j=i+1;j<heights.size();j++){
                    maxx=max(maxx,heights[j]);
                    if(rects.size()==2 && maxx<rects[0] && maxx>rects[1]){
                        rects.pop_back();
                        rects.push_back(maxx);
                        ind2=j;
                    }
                    else if(maxx<rects[0] && rects.size()==1){
                        rects.push_back(maxx);
                        ind2=j;
                    }
                    else{
                        continue;
                    }
                }
            }
        }

        if(abs(ind1-ind2)==1) return 2*heights[ind2];
        if(abs(ind1-ind2)>1){
            int left=abs(ind1-ind2);
            if(ind1>ind2){
                int minn=INT_MAX;
                for(int j=ind1;j<ind2;j++){
                    minn=min(minn,heights[j]);
                }
                return (left+2)*minn;
            }
            else{
                int minn=INT_MAX;
                for(int j=ind1;j<ind2;j++){
                    minn=min(minn,heights[j]);
                }
                return (left+2)*minn;
            }
        }
        int sum=0;
        for(int i=0;i<heights.size();i++){
            sum+=heights[i];
        }

        return sum;
    */
    }
};