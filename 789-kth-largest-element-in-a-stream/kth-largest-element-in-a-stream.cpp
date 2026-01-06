class KthLargest {
public:
/*
    void heapify(vector<int>& nums,int n, int i){
        int largest=i;
        int left=2*i + 1;
        int right = 2*i + 2;

        if(left<n && nums[left]>nums[largest]) largest=left;
        if(right<n && nums[right]>nums[largest]) largest=right;

        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapify(nums,n ,largest);
        }
    }

    vector<int> numss;

    int pos=0;
    */
    priority_queue<int , vector<int>, greater<int>> minn;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int num:nums){
            minn.push(num);
        }

        while(minn.size()>k) minn.pop();
    }

    
    int add(int val) {

        minn.push(val);

        while(minn.size()>size) minn.pop();

        return minn.top();
        /*
        numss.push_back(val);
        int n= numss.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(numss,n,i);
        }

        for(int i=0;i<pos-1;i++){
            swap(numss[0],numss[n-i-1]);
            heapify(numss,n-i-1,0);
        }
        int kk=numss[0];
        return kk;
        */
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */