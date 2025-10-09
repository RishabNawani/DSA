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
        // Base case
        if (!head || !head->next) return head;

        // 1️⃣ Split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // Split into two lists

        // 2️⃣ Recursively sort each half
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // 3️⃣ Merge the two sorted halves
        return merge(leftSorted, rightSorted);
    }

private:
    // Helper to find the middle of the list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // start fast one step ahead

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        tail->next = (l1) ? l1 : l2;
        return dummy.next;
    }
};

 /*
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

*/