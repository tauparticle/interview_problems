/*
 101. Symmetric Tree   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 148586
 Total Submissions: 402907
 Difficulty: Easy
 Contributors: Admin
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 But the following [1,2,2,null,3,null,3] is not:
 1
 / \
 2   2
 \   \
 3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
    
    bool compare(TreeNode* a, TreeNode* b)
    {
        if (!a && !b)
        {
            return true;
        }
        if (a && !b || !a && b || a->val != b->val)
        {
            return false;
        }
        
        return compare(a->left, b->right) && compare(a->right, b->left);
    }
};
