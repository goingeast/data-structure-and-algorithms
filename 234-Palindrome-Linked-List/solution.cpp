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

    bool isPalindrome(ListNode* head){
        ListNode* temp = head;
       
        return isPalindrome_helper(temp, head);
        
    }

    bool isPalindrome_helper(ListNode*&head, ListNode* tail){

        if(tail == NULL)
            return true;
            
        bool is_Valid = isPalindrome_helper(head,tail->next);
        
        if( is_Valid  == false || head->val != tail->val){
            return false;
        }
        head = head->next;
    
        return is_Valid;
        
    }
};