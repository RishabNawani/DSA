struct Node{
    Node *links[26];
    bool flag=false;

    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* gett(char ch){
        return links[ch -'a'];
    }

    void setendd(){
        flag=true;
    }

    bool isendd(){
        return flag;
    }

};



class Trie {
public:
    Node* root;
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node=root;

        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->gett(word[i]);
        }
        node->setendd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->gett(word[i]);
        }
        return node->isendd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node=node->gett(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */