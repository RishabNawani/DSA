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
    bool isPalindrome(ListNode* head) {
        std::vector<int> storee;

        ListNode* ptr= head;
        while(ptr!=NULL){
            storee.push_back(ptr->val);
            ptr=ptr->next;
        }

        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head=prev;

        std::vector<int> storee1;

        ListNode* pt= head;
        while(pt!=NULL){
            storee1.push_back(pt->val);
            pt=pt->next;
        }

        int i=0;
        while(i<storee.size()){
            if(storee[i]!=storee1[i]) return false;
            i++;
        }

        return true;
    }
};