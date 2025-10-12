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
        while(temp!=NULL){
            Node* copyy=new Node(temp->val);
            copyy->next=temp->next;
            temp->next=copyy;
            temp=temp->next->next;
        }

        temp=head;

        while(temp!=NULL){
            Node* copyyyy= temp->next;
            if(temp->random) copyyyy->random=temp->random->next;
            temp=temp->next->next;

        }

        temp=head;

        Node* dmmy= new Node(-1);
        Node* res= dmmy;

        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dmmy->next;


        /*
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

        */
        
    }
};