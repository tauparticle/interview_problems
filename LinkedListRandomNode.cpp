/**
 
 Follow up:
 What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
 
 Example:
 
 // Init a singly linked list [1,2,3].
 ListNode head = new ListNode(1);
 head.next = new ListNode(2);
 head.next.next = new ListNode(3);
 Solution solution = new Solution(head);
 
 // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 solution.getRandom();
 Hide Company Tags Google
 Hide Tags Reservoir Sampling

 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        m_head = head;
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        ListNode* current = m_head;
        ListNode* result = current;
        
        // this is resoivore sampling.  Continusouly sample random numbers as you increase the sample and
        // record exact matches with growing index.  Reord each match as you go and return last.
        for (int i=1; current != nullptr; ++i)
        {
            if (rand() % i == 0)
            {
                result = current;
            }
            current = current->next;
        }
        
        return result->val;
        
    }
    
private:
    ListNode* m_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */