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

/*
// RECURSIVELY CONNECTING HEAD TO END OF LIST AFTER REVERSING FROM HEAD->NEXT
class Solution {
public:
    ListNode* reverseLL(ListNode* &head) {
        ListNode* cur=head, *prv=NULL, *nxt;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
    
    void reorderList(ListNode* &head) {
        if(head==NULL){
            return;
        }
        // in fn, we connect head to end of list after reversing it
        // reverse the linked list from head->next
        ListNode* revhead = reverseLL(head->next);
        head->next = revhead;
        reorderList(head->next);
    }
};
*/

// REVERSING FROM MID TO END AND CONNECTING HEAD TO REVHEAD AND REVHEAD TO HEAD->NEXT
class Solution {
public:
    // reverse linked list and return new head
    ListNode* reverseList(ListNode* &head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *prv = NULL, *cur = head, *nxt = head->next;
        while(cur){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
    
    void reorderList(ListNode* head) {
        // we need min 3 elements in list
        if(!head || !head->next || !head->next->next){
            return;
        }
        // find mid of linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the part after mid of linked list
        // in [1,2,3,4,5] mid is 3. we split the list to [1,2,3] and [5,4]
        ListNode* ptr = head;
        ListNode* revptr = reverseList(slow->next);
        slow->next = NULL;
        
        while(ptr && revptr && ptr!=revptr){
            ListNode* nextptr = ptr->next;
            ListNode* nextrevptr = revptr->next;
            
            // at each step, point ptr->next to revptr and revptr->next to next of og ptr
            // in [1,2,3,4,5], point 1->next to 5 and 5->next to 2. then make 2 as ptr and 4 as revptr.
            ptr->next = revptr;
            revptr->next = nextptr;
            
            ptr = nextptr;
            revptr = nextrevptr;
        }
    }
};