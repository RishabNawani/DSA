class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         // Size of array
        int n = nums.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // To store the smallest value of subarray
            int smallest = nums[i];
            
            // To store the largest value of subarray
            int largest = nums[i];
            
            /* Nested loop to get all 
            subarrays starting from index i */
            for(int j=i; j < n; j++) {
                
                // Update the smallest value
                smallest = min(smallest, nums[j]);
                
                // Update the largest value
                largest = max(largest, nums[j]);
                
                // Update the sum
                sum += (largest - smallest);
            }
        }
        
        // Return the computed sum
        return sum;
        /*

        int sum=0;
        for(int i=0;i<nums.size();i++){
            int maxx=nums[i];
            int minn=nums[i];
            for(int j=i;j<nums.size();j++){
                maxx=max(nums[j],maxx);
                minn=min(nums[j],maxx);
                sum=sum+ maxx-minn;
            }
        }
        return (long long)sum;
    
        vector<vector<int>> sumarray;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                sumarray.push_back(std::vector<int>(nums.begin()+i,nums.begin()+j+1));
            }
        }

        for(int i=0;i<sumarray.size();i++){
            int max=INT_MIN;
            int min=INT_MAX;
            for(int val: sumarray[i]){
                max=max(val,max);
                min=min(val,min);
            }
            sum+=(long long)(max-min);
            
        }
        return sum;
    */
    }
};