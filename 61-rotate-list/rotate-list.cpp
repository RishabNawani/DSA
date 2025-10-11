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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* ptr=head;
        int i=1;
        while(ptr->next!=NULL){
            i++;
            ptr=ptr->next;
        }
        if(k%i==0) return head;
        k=k%i;
        int j=i-k;
        ListNode* p=head;
        ptr->next=head ;
        for(int a=0; a<j-1;a++){
            p=p->next;
        }
        head=p->next;
        p->next=NULL;
        return head;
    }
};