class LFUCache {
public:
    class Node{
    public:
        int keyy;
        int vall;
        int cnt;
        Node* next;
        Node* prev;
        Node(int keyyy,int valll){
            keyy=keyyy;
            vall=valll;
            cnt=1;
        }
    };

    class List{
    public:
        int size;
        Node* head;
        Node* tail;

        List(){
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addNode(Node* newww){
            Node* temp=head->next;
            head->next=newww;
            newww->next=temp;
            newww->prev=head;
            temp->prev=newww;
            size++;
        }

        void delNode(Node* delll){
            Node* deln=delll->next;
            Node* delp=delll->prev;
            deln->prev=delp;
            delp->next=deln;
            size--;
        }
    };

    int cap;
    unordered_map<int,Node*> m;
    unordered_map<int,List*> freqq;
    int minfreq;
    int cursizee;


    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
        cursizee=0;
    }

    void updatefreqq(Node* node){
        m.erase(node->keyy);

        freqq[node->cnt]->delNode(node);
        if(node->cnt==minfreq && freqq[node->cnt]->size==0){
            minfreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqq.find(node->cnt + 1) != freqq.end()) {
           nextHigherFreqList = freqq[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addNode(node); 
        freqq[node->cnt] = nextHigherFreqList; 
        m[node->keyy] = node; 
    }

   
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* node = m[key]; // Get the node
            int val = node->vall; // Get the value
            updatefreqq(node); // Update the frequency
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(m.find(key)!=m.end()){
            Node* node= m[key];
            node->vall=value;

            updatefreqq(node);
        }

        // Else if the key does not exist
        else {
           
           // If cache limit is reached
            if(cursizee == cap) {
               
               // Remove the least frequently used data-item
               List* list = freqq[minfreq]; 
               m.erase(list->tail->prev->keyy); 
               
               // Update the frequency map 
               freqq[minfreq]->delNode(list->tail->prev);
               
               // Decrement the current size of cache
               cursizee--; 
            }
           
            // Increment the current cache size
            cursizee++; 
           
            // Adding new value to the cache
            minfreq = 1; // Set its frequency to 1
           
            // Create a dummy list
            List* listFreq = new List(); 
           
            // If the list already exist
            if(freqq.find(minfreq) != freqq.end()) {
               // Update the pointer to already present list
               listFreq = freqq[minfreq]; 
            }
           
            // Create the node to store data-item
            Node* node = new Node(key, value); 
           
            // Add the node to dummy list
            listFreq->addNode(node);
           
            // Add the node to Hashmap
            m[key] = node; 
           
            // Update the frequency list map 
            freqq[minfreq] = listFreq; 
       }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */