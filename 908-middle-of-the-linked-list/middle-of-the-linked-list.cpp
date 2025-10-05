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
    ListNode* middleNode(ListNode* head) {
        ListNode* p=head;
        int i=1;
        while(p->next!=NULL){
            p=p->next;
            i++;
        }

        int n=i%2;
        int j=i/2;
        int l=0;

        ListNode* ptr=head;
        if(n==1){
            while(l<j){
                ptr=ptr->next;
                l++; 
            }
            return ptr;
        }
        if(n==0){
            while(l<j){
                ptr=ptr->next;
                l++;
            }
        }
        return ptr;
    }
};