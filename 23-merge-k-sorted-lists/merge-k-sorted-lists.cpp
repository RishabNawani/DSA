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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > minn;

        for(int i=0;i<lists.size();i++){
    
            ListNode* head = lists[i];
            while(head !=NULL){
                int s=head-> val;
                minn.push(s);
                head=head->next;
            }
        }

        if(minn.empty()) return NULL;
    
        ListNode* headd= new ListNode(minn.top());
        minn.pop();
        ListNode* taill=headd;

        while(!minn.empty()){
            taill->next= new ListNode(minn.top());
            minn.pop();
            taill=taill->next;
        }
        return headd;


    }
};