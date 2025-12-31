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
    void heapify(vector<int>& nums,int n, int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[largest]<nums[left]) largest=left;
        if(right<n && nums[largest]<nums[right]) largest=right;

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
    void heapsort(vector<int>& nums,int n){
        int size=n;

        while(size>1){
            swap(nums[size-1],nums[0]);
            size--;

            heapify(nums,size,0);
        }
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
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
*/
        vector<int> storee;

        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head !=NULL){
                int s=head-> val;
                storee.push_back(s);
                head=head->next;
            }
        }
        if(storee.empty()) return NULL;
        int n=storee.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(storee,n,i);
        }

        heapsort(storee,n);

        ListNode* headd= new ListNode(storee[0]);
        ListNode* taill=headd;

        for(int i=1;i<n;i++){
            taill->next=new ListNode(storee[i]);
            taill=taill->next;
        }
        return headd;
    }
};