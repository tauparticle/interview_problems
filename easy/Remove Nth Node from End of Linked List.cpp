/**
 
 Remove Nth Node From End of List
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* runner = head;
        ListNode* tail = head;
        ListNode* prev = nullptr;
        
        while (n-- > 0)
        {
            runner = runner->next;
        }
        
        while (runner)
        {
            runner = runner->next;
            prev = tail;
            tail = tail->next;
        }
        
        ListNode* deleteMe = tail;
        
        // tail should now point to the node that needs to be deleted
        if (tail == head)
        {
            // special case for deleting the head
            head = head->next;
        }
        else
        {
            prev->next = tail->next;
        }
        
        delete deleteMe;
        return head;
        
    }
};
