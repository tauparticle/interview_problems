/*
 Merge k Sorted Lists
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

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
    
    struct NodeCompare
    {
        bool operator() (const ListNode* l, const ListNode* r)
        {
            return l->val > r->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> pq;
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        
        // push first element onto queue
        for (ListNode *h : lists)
        {
            if (h)
            {
                pq.push(h);
            }
        }
        
        while (pq.size() > 0)
        {
            // get min element
            ListNode* n = pq.top();
            pq.pop();
            
            current->next = n;
            current = current->next;
            if (n->next)
            {
                pq.push(n->next);
            }
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
        
    }
};
