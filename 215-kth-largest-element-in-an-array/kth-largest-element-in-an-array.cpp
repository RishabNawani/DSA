class Solution {
public:
/*
    void heapify(vector<int>& nums,int n, int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<n && nums[largest]<nums[left]) largest=left;
        if(right<n && nums[largest]<nums[right]) largest=right;

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
*/
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size()-1;
/*
        for(int i=n/2;i>0;i--){
            heapify(nums,n,i);
        }

        return nums[0];
        */

        sort(nums.begin(),nums.end());
        return nums[n-k+1];

    }   
};