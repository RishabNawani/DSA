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

    ListNode* reversee(ListNode* head){
        ListNode* grphead=head;
        ListNode* prev=NULL;
        while(grphead!=NULL){
            ListNode* front=grphead->next;
            grphead->next=prev;
            prev=grphead;
            grphead=front;
        }
        return prev;
    }

    ListNode* getkthnode(ListNode* temp, int k){
        k--;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        ListNode* prevheadd=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevheadd) prevheadd->next=temp;
                break;
            }

            ListNode* next=kthnode->next;
            kthnode->next=NULL;

            reversee(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevheadd->next=kthnode;
            }

            prevheadd=temp;
            temp=next;

        }

        return head;


/*

        if(head==NULL || k==1) return head;
        int i=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            i++;
            ptr=ptr->next;
        }

        int rounds=i/k;

        int start=0;
        ListNode* curr=head;
        ListNode* prevgrphead=NULL;
        ListNode* prevgrptail=NULL;
        for(start;start<rounds;start++){
            int j=0;
            ListNode* grphead=curr;
            ListNode* prev=NULL;
            while(curr!=NULL && j<k){
                ListNode* front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                j++;
            }

            if(prevgrphead==NULL){
                prevgrphead=prev;
            }
            if(prevgrptail!=NULL){
                prevgrptail->next=prev;
            }

            prevgrptail=grphead;

        }

        if(prevgrptail!=NULL){
            prevgrptail->next=curr;
        }
        return prevgrphead;
*/
    }
};