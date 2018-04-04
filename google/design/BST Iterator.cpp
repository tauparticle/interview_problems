/*Binary Search Tree Iterator
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 
 Calling next() will return the next smallest number in the BST.
 
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        goLeft(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        
        TreeNode* node = m_stack.top();
        m_stack.pop();
        goLeft(node->right);
        return node->val;
    }
    
private:
    
    void goLeft(TreeNode* node)
    {
        while (node)
        {
            m_stack.push(node);
            node = node->left;
        }
    }
    
    stack<TreeNode*> m_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
