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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy node used for deleting head if required
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* fast = dummy;
        for(int i=0;i<n+1;i++){
            fast = fast->next;
        }
        
        ListNode* slow = dummy;
        
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        // now head2 is at n+1'th node from end of list
        // delete next node and connect next to next of next
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return dummy->next;
    }
};