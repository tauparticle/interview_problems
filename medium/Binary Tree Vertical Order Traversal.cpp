/*144. Binary Tree Preorder Traversal   QuestionEditorial Solution  My Submissions
Total Accepted: 146794
Total Submissions: 347920
Difficulty: Medium
Contributors: Admin
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Tags Tree Stack
Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Verify Preorder Sequence in Binary Search Tree

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }

            if(!s.empty()){
                auto node = s.top();
                s.pop();
                root = node->right;
            }
        }
        return result;
    }
    
    // another one that's easier
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            auto n = s.top();
            s.pop();
            res.push_back(n->val);
            
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
        }
        return res;
        
    }
};
