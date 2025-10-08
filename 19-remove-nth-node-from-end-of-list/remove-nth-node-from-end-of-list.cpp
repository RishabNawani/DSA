/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front= temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head=prev;

        temp=head;
        prev=NULL;

        if(n==1) head=head->next;
        else{
            int count=1;
            while(temp!=NULL && count<n){
                prev=temp;
                temp=temp->next;
                count++;
            }
            if(temp!=NULL){
                prev->next=temp->next;
            }
        }

        


        ListNode* tempp=head;
        ListNode* prevv=NULL;
        while(tempp!=NULL){
            ListNode* front= tempp->next;
            tempp->next=prevv;
            prevv=tempp;
            tempp=front;
        }
        head=prevv;
        return head;

/*
        ListNode* ptr=head;
        int i=0;
        while(ptr!=NULL){
            i++;
            ptr=ptr->next;
        }
        ListNode* p=head;
        int left=i-n+1;
        for(int j=1; j<i;j++){
            if(p->next!=NULL) break;
            else if(j==left) continue;
            else if(j==left-1){
                p=p->next->next;
            }
            else{
                p=p->next;
            }
        }

        return head;
        
*/
    }
};