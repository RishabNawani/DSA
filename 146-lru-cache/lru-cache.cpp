class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int keyy, int vall){
            key=keyy;
            val=vall;
        }
    };

    int cap;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newww){
        Node* temp= head->next;
        newww->next=temp;
        newww->prev=head;
        head->next= newww;
        temp->prev=newww;
    }

    void delNode(Node* delll){
        Node* deln = delll->next;
        Node* delp = delll->prev;
        delp->next=deln;
        deln->prev=delp;
    }


    int get(int key){
        if(m.find(key)!=m.end()){
            Node* ress= m[key];
            int resss= ress->val;
            m.erase(key);
            delNode(ress);
            addNode(ress);
            m[key]=head->next;
            return resss;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* existt= m[key];
            m.erase(key);
            delNode(existt);
        }

        if(m.size()==cap){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(new Node(key,value));
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */