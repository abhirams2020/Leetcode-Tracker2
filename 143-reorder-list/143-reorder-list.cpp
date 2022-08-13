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
    ListNode* reverseLL(ListNode* head) {
        ListNode* cur=head, *prv=NULL, *nxt;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
    void reorderList(ListNode* head) {
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