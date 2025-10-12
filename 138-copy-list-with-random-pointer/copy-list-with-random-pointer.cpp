/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*, Node*> mpp;
        while(temp!=NULL){
            Node* newww= new Node(temp->val);
            mpp[temp]=newww;
            temp=temp->next;
        }

        temp=head;

        while(temp!=NULL){
            Node* copyy=mpp[temp];
            copyy->next=mpp[temp->next];
            copyy->random=mpp[temp->random];
            temp=temp->next;
        }

        return mpp[head];
        
    }
};