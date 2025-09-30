class Solution {
public:
    string frequencySort(string s) {
    vector<int> freq(256,0);
    for(char c: s){
        freq[c]++;
    }
    vector<pair<char,int>> idk;
    for(int i=0; i<256;i++){
            if(freq[i]>0){
                idk.push_back({(char)i,freq[i]});
            }
    }

    std::sort(idk.begin(),idk.end(),[](auto &a, auto&b) {
        return a.second>b.second;
        } );
    std::string res="";
    for(auto &p: idk){
        res.append(p.second,p.first);
    }
    return res;
    }
};