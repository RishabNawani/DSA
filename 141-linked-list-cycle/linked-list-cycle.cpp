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
    bool hasCycle(ListNode *head) {

        // Initialize a pointer 'temp'
        // at the head of the linked list
        ListNode* temp = head;  
        
        // Create a map to keep track of
        // encountered nodes
        std::unordered_map<ListNode*, int> nodeMap;  

        // Step 2: Traverse the linked list
        while (temp != nullptr) {
            // If the node is already in the
            // map, there is a loop
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node
            // in the map
            nodeMap[temp] = 1;
            
            // Move to the next node
            temp = temp->next;  
        }

        // Step 3: If the list is successfully traversed 
        // without a loop, return false
        return false;

/*

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }

        return false;


*/

        /*this fails cause if the it has a loop, while condition wont terminate at all as it doesnt reach null, hence will never break hence infinity


        ListNode* ptr= head;
        int i=0;
        while(ptr->next!=NULL){
            i++;
            ptr=ptr->next;
        }
        ListNode* p=head;
        for(int j=0; j<=i;j++){
            
            if(ptr==p || p==NULL) return false;
            else if(ptr->next==p) return true;
            p=p->next;
        }
        return false;
        */
    }
};