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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;

/*
        std::vector<int> storee;

        ListNode* ptr= head;
        while(ptr!=NULL){
            storee.push_back(ptr->val);
            ptr=ptr->next;
        }
        ListNode* p=head;
        for(int i=storee.size()-1; i>=0;i--){
            p->val=storee[i];
            p=p->next;
        }

        return head;
*/
        
    }
};