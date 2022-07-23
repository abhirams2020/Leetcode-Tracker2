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
    int lengthLL(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return 1 + lengthLL(head->next);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int len = lengthLL(head);
        k = k % len;
        if(k==0){
            return head;
        }
        ListNode *fast=head, *slow=head; 
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        // currently fast at last node and slow->next to fast size is 2
        // to get rotated list, point slow->next to null and fast->next to head and make head = slow->next
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};