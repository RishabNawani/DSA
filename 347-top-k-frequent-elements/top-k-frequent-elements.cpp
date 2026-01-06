class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1) return nums;
        if(nums.empty()) return {};
        map<int,int> storage;

        for(int num:nums){
            storage[num]++;
        }

        vector<int> storee;

        for(int i=0;i<k;i++){
            int maxx=0;
            for(auto it : storage){
                maxx=max(maxx, it.second);
            }
            for(auto itt:storage){
                if(itt.second==maxx){
                    storee.push_back(itt.first);
                    storage.erase(itt.first);
                    break;
                }
            }
        }

        return storee;
    }
};