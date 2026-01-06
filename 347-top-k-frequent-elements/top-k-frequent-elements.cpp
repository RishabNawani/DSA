class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        
        if(nums.size()==1) return nums;
        if(nums.empty()) return {};
        /*
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
        */

        unordered_map<int ,int> mpp;
        int n=nums.size();

        for(int num:nums){
            mpp[num]++;
        }
    

        vector<vector<int>>bucket(n+1);

        for(auto it : mpp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ress;

        for(int i=n;i>=0;i--){
            if(bucket[i].size()==0) continue;

            while(bucket[i].size()>0 && k>0){
                ress.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }

        }

        return ress;

    }
};