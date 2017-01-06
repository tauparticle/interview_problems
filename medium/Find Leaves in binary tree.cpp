/*
 366. Find Leaves of Binary Tree   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 10585
 Total Submissions: 18561
 Difficulty: Medium
 Contributors: Admin
 Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
 
 Example:
 Given binary tree
 1
 / \
 2   3
 / \
 4   5
 Returns [4, 5, 3], [2], [1].
 
 Explanation:
 1. Removing the leaves [4, 5, 3] would result in this tree:
 
 1
 /
 2
 2. Now removing the leaf [2] would result in this tree:
 
 1
 3. Now removing the leaf [1] would result in the empty tree:
 
 []
 Returns [4, 5, 3], [2], [1].
 
 Credits:
 Special thanks to @elmirap for adding this problem and creating all test cases.
 
 Hide Company Tags LinkedIn
 Hide Tags Tree Depth-first Search
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* node, vector<vector<int>>& res)
    {
        if (!node) return 0;
        int leftLevel = dfs(node->left, res);
        int rightLevel = dfs(node->right, res);
        int level = max(leftLevel, rightLevel) + 1;
        
        if (level > res.size())
        {
            res.push_back(vector<int>());
        }
        
        res[level-1].push_back(node->val);
        return level;
    }
};
