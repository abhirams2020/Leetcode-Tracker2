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
    
    int linkedListLen(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return 1 + linkedListLen(head->next);
    }
    
    void printLL(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<"\n";
    }
    
    bool isPalindrome(ListNode* head) {
        int len = linkedListLen(head);
        // find mid of linked list
        ListNode *slow=head, *fast=head;
        // if odd size, slow stops at mid. if even size, slow stops at left mid
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* revhead;
        // linked list is even length
        // linked list seperate into start to mid, mid+1 to end for checking palindrome
        if(len%2==0){
            revhead = mid->next;
        }
        // linked list is odd length
        // linked list seperate into start to mid, mid to end for checking palindrome
        else {
            revhead = mid;
        }
        // reverse linked list revhead to end and point revhead to head of reversed list
        revhead = reverseLL(revhead);

        mid->next = NULL; // imp : head should only go till mid while checking
        
        // printLL(head);
        // printLL(revhead);
        while(revhead && head){
            if(revhead->val != head->val){
                return false;
            }
            revhead = revhead->next;
            head = head->next;
        }
        
        return (head==NULL) && (revhead==NULL);
    }
};