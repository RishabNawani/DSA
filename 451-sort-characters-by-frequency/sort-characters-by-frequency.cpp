class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        
        vector<vector<char>> bucket(s.length()+1);
        for(auto &p:freq){
            bucket[p.second].push_back(p.first);
        }

        std::string res="";
        for(int i=s.length();i>0;i--){
            for(char c:bucket[i]){
                res.append(i,c);
            }
        }
        return res;




    /*
    vector<int> freq(256,0); /// make a freq array using hashing method
    for(char c: s){
        freq[c]++;/// index value increase.
    }
    vector<pair<char,int>> idk; /// then create a pair data type inside the vector to store both the character and its occurence instances
    for(int i=0; i<256;i++){
            if(freq[i]>0){ /// we have given array at each ascii value that is from 0 to 255, so if for b exists then character at index 97 will be increased
                idk.push_back({(char)i,freq[i]});/// push the char and its instances to the pair
            }
    }

    std::sort(idk.begin(),idk.end(),[](auto &a, auto&b) {
        return a.second>b.second;/// sort because if we sort the normal way it wont across for example in tree , if we sort normally then it woould give {e,2},{r,1} and {t,1} not e,t,r. so we pass reference to each pair and whose instance is greater is returned first.
        } );
    std::string res="";
    for(auto &p: idk){
        res.append(p.second,p.first);/// append first whose int is greater
    }
    return res;
    */
    }
};


