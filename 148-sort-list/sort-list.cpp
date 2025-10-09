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
    ListNode* sortList(ListNode* head) {
        std::vector<int> storage;

        ListNode* ptr=head;
        while(ptr!=NULL){
            storage.push_back(ptr->val);
            ptr=ptr->next;
        }

        std::sort(storage.begin(),storage.end());

        ListNode* p=head;
        for(int i=0; i<storage.size();i++){
            p->val=storage[i];
            p=p->next;
        }
        return head;
        
    }
};