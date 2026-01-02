class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);

        for(char &c : tasks){
            mp[c-'A']++;
        }

        int time=0;
        priority_queue<int> freqq;

        for(int i=0;i<26;i++){
            if(mp[i]>0){
                freqq.push(mp[i]);
            }
        }

        while(!freqq.empty()){
            vector<int> tempp;

            for(int i=1;i<=n+1;i++){
                if(!freqq.empty()){
                    int freq= freqq.top();
                    freqq.pop();
                    freq--;
                    tempp.push_back(freq);
                }
            }

            for(int f: tempp){
                if(f>0){
                    freqq.push(f);
                }
            }

            if(freqq.empty()){
                time+=tempp.size();
            }
            else{
                time+=n+1;
            }
        }

        return time;
    }
};