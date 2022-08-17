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
    ListNode* reverseLL(ListNode* head){
        ListNode *prev=NULL, *curr=head, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        // find midPoint
        ListNode* slow=head, *fast=head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse from mid->next to end and make mid->next = NULL
        ListNode* revhead = reverseLL(slow->next);
        slow->next = NULL;
        
        int maxVal = INT_MIN;
        // add head and revhead val and compare to maxval. then move head and revhead by 1 place
        while(head && revhead){
            maxVal = max(maxVal, head->val + revhead->val);
            head = head->next;
            revhead = revhead->next;
        }
        return maxVal;
    }
};