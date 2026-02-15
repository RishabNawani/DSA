class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> qq;
        qq.push({beginWord,1});
        unordered_set<string> stt(wordList.begin(),wordList.end());

        stt.erase(beginWord);

        while(!qq.empty()){
            string word=qq.front().first;
            int len=qq.front().second;
            qq.pop();
            if(word==endWord) return len;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;

                    if(stt.find(word)!=stt.end()){
                        stt.erase(word);
                        qq.push({word,len+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};