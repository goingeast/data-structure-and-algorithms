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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int sum = 0;
        while(sum > 0 || l1 || l2){
        	if(l1){
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if(l2){
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	
        	tail->next = new ListNode(sum%10);
        	sum = sum / 10;
        	tail = tail->next;
        }
        return dummy.next;
    }
};