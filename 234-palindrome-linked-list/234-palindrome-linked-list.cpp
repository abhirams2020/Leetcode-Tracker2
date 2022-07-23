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