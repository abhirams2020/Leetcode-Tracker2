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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* dummy = new ListNode();
        dummy->val = INT_MIN;
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1){
            curr->next = l1;
        }
        if(l2){
            curr->next = l2;
        }
        return dummy->next;
    }
    
    ListNode* mergeLists(vector<ListNode*>& lists, int lo, int hi){
        if(lo>hi){
            return NULL;
        }
        if(lo==hi){
            return lists[lo];
        }
        int mid = lo+(hi-lo)/2;
        ListNode* a = mergeLists(lists,lo,mid);
        ListNode* b = mergeLists(lists,mid+1,hi);
        return mergeTwoLists(a,b);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int K = lists.size();
        return mergeLists(lists,0,K-1);
    }
};