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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // traverse headA and headB using ptr1 and ptr2.
        // when a ptr reaches NULL, switch the head. ie ptr2 = headB
        // the meeting point is where ptr1 and ptr2 meet
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1 != ptr2){
            if(ptr1==NULL){
                ptr1 = headB;
            }
            else {
                ptr1 = ptr1->next;
            }
            if(ptr2==NULL){
                ptr2 = headA;
            }
            else {
                ptr2 = ptr2->next;
            }
        }
        return ptr1;
    }
};