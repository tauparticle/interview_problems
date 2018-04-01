/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 null -> 1 -> 2 -> null
 prev    c    n
 
 p    c
 */


class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* next = head;
        
        
        while (current)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        return previous;
        
    }
};
