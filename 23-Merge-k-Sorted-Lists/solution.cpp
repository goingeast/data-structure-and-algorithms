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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return NULL;
         return _mergeKLists(lists,0, lists.size() -1);   
    }
    ListNode* _mergeKLists(vector<ListNode *> &lists, int leftIndex, int rightIndex){
        if(leftIndex < rightIndex){
            int mid = (leftIndex+rightIndex)/2;
            return mergeTwoLists( _mergeKLists(lists, leftIndex, mid), _mergeKLists(lists, mid+1, rightIndex));
        }
        return lists[leftIndex];
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        ListNode* head = new ListNode(0);
        ListNode* iter = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                iter->next = l2;
                
                l2 = l2->next;
            }else{
                iter->next = l1;
                l1 = l1->next;
            }
            iter = iter->next;
        }
        if(l1 == NULL){
            iter->next = l2;
        }else{
            iter->next = l1;
        }
        return head->next;
    }
};