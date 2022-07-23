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
// REVERSING THE LINKED LIST AND COMPARING TO VECTOR OF ORIGINAL LINKED LIST
class Solution {
public:
    vector<int> printLL(ListNode* head){
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }
    
    ListNode* reverseLL(ListNode* head){
        ListNode* prv = NULL, *cur = head, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> a = printLL(head);
        vector<int> b = printLL(reverseLL(head));
        return a == b;
    }
};
*/

class Solution {
public:
    // reverse LL and return its head
    ListNode* reverseLL(ListNode* head){
        ListNode* prv = NULL, *cur = head, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }
        // find mid of linked list
        ListNode *slow=head, *fast=head;
        // if odd size, slow stops at mid. if even size, slow stops at right mid
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midhead = slow;
        
        // reverse linked list revhead to end and point revhead to head of reversed list
        ListNode* revhead = reverseLL(midhead);
        
        // move LL till head!=revhead for odd length LL
        // move LL till revhead!=NULL for even length LL
        while(head && revhead && head!=revhead){
            if(revhead->val != head->val){
                return false;
            }
            revhead = revhead->next;
            head = head->next;
        }
        
        return true;
    }
};