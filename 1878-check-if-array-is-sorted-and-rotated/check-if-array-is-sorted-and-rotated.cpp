class Solution {
public:
    bool check(vector<int>& nums) {
        vector <int> b=nums;
        std::sort(b.begin(),b.end());
        int a= nums.size();
        int rot=0;
        
        for(rot; rot<a; rot++){
            rotate(b.begin(), b.begin()+1,b.end());
            if(nums==b){
                return true;
            }
        }
        
        return false;



    }
};
