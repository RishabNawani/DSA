class MedianFinder {
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

    void heapsort(vector<int>& nums,int n){
        int size=n;

        while(size>1){
            swap(nums[size-1],nums[0]);
            size--;

            heapify(nums,size,0);
        }
    }
    vector<int> numss;
    */
    priority_queue<int,vector<int>,greater<int>> minn;
    priority_queue<int> maxx;





    //priority_queue<int , vector<int> , greater<int>> minn;
    //priority_queue<int> maxx;
    
   /* MedianFinder() {
    }
    */
    void addNum(int num) {

        maxx.push(num);

        minn.push(maxx.top());
        maxx.pop();

        if(minn.size()>maxx.size()){
            maxx.push(minn.top());
            minn.pop();
        }
/*
        maxx.push(num);

        minn.push(maxx.top());
        maxx.pop();

        if(minn.size()>maxx.size()){
            maxx.push(minn.top());
            minn.pop();
        }
        
        numss.push_back(num);
        int n= numss.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(numss,n,i);

        }

        heapsort(numss,n);
        */
    }
    
    double findMedian() {

        if(maxx.size()==minn.size()) return ((double)maxx.top()+minn.top())/2.0;
        return maxx.top();
        
        /*
        if(maxx.size()==minn.size()) return ((double)maxx.top()+(double)minn.top())/2.0 ;
        return maxx.top();
        
        int n=numss.size();
        if(n%2==0) return (((double)numss[n/2]+(double)numss[n/2 -1])/2);

        return (double)numss[n/2];
        */
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */