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
    // we cannot delete curr node since we need previous to point to curr address
    // so copy contents of next to curr, and delete next
    void deleteNode(ListNode* node) {
        ListNode* cur = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete cur;
        cur = NULL;
    }
};