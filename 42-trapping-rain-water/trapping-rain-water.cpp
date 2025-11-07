class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n);
        vector<int> suf(n);
        int total=0;
        pre[0]=height[0];
        suf[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            int leftmax=pre[i];
            int rightmax=suf[i];
            total+=min(leftmax,rightmax)-height[i];
        }
        return total;
    }
};