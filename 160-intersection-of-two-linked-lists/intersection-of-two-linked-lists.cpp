/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA= headA;
        ListNode* ptrB= headB;

        while(ptrA!=ptrB){
            if(ptrA==NULL) ptrA=headB;
            else{
                ptrA=ptrA->next;
            }

            if(ptrB==NULL) ptrB=headA;
            else{
                ptrB=ptrB->next;
            }
        }


        return ptrA;

        /*
        ListNode* fastA= headA;
        ListNode* fastB= headB;

        ListNode* slowA= headA;
        ListNode* slowB= headB;

        while(fastA!=NULL && fastA->next!=NULL){
            fastA=fastA->next->next;
            slowA=slowA->next;

        }
        while(fastB!=NULL && fastB->next!=NULL){
            fastB=fastB->next->next;
            slowB=slowB->next;

        }

        if(slowA == slowB) return slowA;

        return NULL;

        
        
        
        
        ListNode* ptrA= headA;
        ListNode* ptrB= headB;



        while(ptrA!=NULL){
            ptrA=ptrA->next;
        }
        while(ptrB!=NULL){
            ptrB=ptrB->next;
        }

        if(ptrA!=ptrB) return NULL;


        ListNode* tempa= headA;
        ListNode* tempb=headB;

        ListNode* preva= NULL;
        ListNode* prevb=NULL;

        while(tempa!=NULL){
            ListNode* fronta= tempa->next;
            tempa->next=preva;
            preva=tempa;
            tempa=fronta;
        }
        
        headA=preva;

        while(tempb!=NULL){
            ListNode* frontb= tempb->next;
            tempb->next=prevb;
            prevb=tempb;
            tempb=frontb;
        }
        headB=prevb;
        ptrA=headA;
        ptrB=headB;


        ListNode* prevv=NULL;

        while(ptrA==ptrB){
            prevv=ptrA;
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        
        }


        while(tempa!=NULL){
            ListNode* fronta= tempa->next;
            tempa->next=preva;
            preva=tempa;
            tempa=fronta;
        }
        
        headA=preva;

        while(tempb!=NULL){
            ListNode* frontb= tempb->next;
            tempb->next=prevb;
            prevb=tempb;
            tempb=frontb;
        }
        headB=prevb;

        return prevv;

*/
        
    }
};