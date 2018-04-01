/**
 Palindrome Linked List
 Given a singly linked list, determine if it is a palindrome.
 
 Follow up:
 Could you do it in O(n) time and O(1) space?
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 a, b, c, d, e
 a->b->c
 */
class Solution {
    public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            s.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast)
        {
            // list is even, pop top off the stack
            slow = slow->next;
        }
        
        
        while (slow)
        {
            if (slow->val != s.top()->val)
            {
                return false;
            }
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};
