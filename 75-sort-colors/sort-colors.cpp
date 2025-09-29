class Solution {
public:
    void sortColors(vector<int>& nums) {
       int newpos=0;
       int n=nums.size();
       int a=0;
       int b=0;
       int c=0;
       for(int i=0; i<n;i++){
        if(nums[i]==0){
            a++;
        }
        else if(nums[i]==1){
            b++;
        }
        else{
            c++;
        }
       }
        for(int j=0; j<a;j++){
            nums[j]=0;
        }
        for(int k=a; k<n-c;k++){
            nums[k]=1;
        }
        for(int l=a+b; l<n;l++){
            nums[l]=2;
        }
       
    
    }
};