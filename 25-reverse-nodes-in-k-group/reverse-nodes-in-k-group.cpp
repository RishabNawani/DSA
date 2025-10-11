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
    ListNode* reverseKGroup(ListNode* head, int k) {

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

    }
};