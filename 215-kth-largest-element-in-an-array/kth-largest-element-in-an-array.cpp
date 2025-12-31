class Solution {
public:

    void heapify(vector<int>& nums,int n, int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[largest]<nums[left]) largest=left;
        if(right<n && nums[largest]<nums[right]) largest=right;

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }


        for(int i=0;i<k-1;i++){
            swap(nums[0],nums[n-i-1]);
            heapify(nums,n-1-i,0);
        }

        return nums[0];

    }   
};