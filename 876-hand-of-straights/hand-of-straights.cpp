class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        
        map<int,int> ff;

        for(int num: hand){
            ff[num]++;
        }

        auto it = ff.begin();

        while(it!=ff.end()){

            if(it->second==0){
                it++;
                continue;
            }
            int startt=it->first;
            int vall=it->second;
            
            for(int i=0;i<groupSize;i++){
                if(ff[startt+i]<vall) return false;
                ff[startt+i]-=vall;
            }
            it++;
            
        }
        return true;

/*
        while(!ff.empty()){
            int curr=ff.begin()->first;

            for(int i=0;i<groupSize;i++){

                if(ff[curr+i]==0) return false;

                ff[curr+i]--;
                if(ff[curr+i]<1) ff.erase(curr+i);
            }
        }
        return true;
        */
    }
};