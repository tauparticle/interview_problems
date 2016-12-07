/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Follow up:
 Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        if (head == null) {
            return null;
        }
        ListNode slow = head;
        ListNode fast = head;
        boolean isCycle = false;
        while (fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            
            if (fast == slow) {
                isCycle = true;
                break;
            }
        }
        
        if (!isCycle) {
            return null;
        }
        
        fast = head;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        
        return fast;
        
    }
}