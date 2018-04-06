/**
 Binary Tree Level Order Traversal
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        dfs(root, 0, levels);
        return levels;
    }
    
    void dfs(TreeNode* node, int depth, vector<vector<int>>& levels)
    {
        if (!node) return;
        if (depth == levels.size())
        {
            levels.push_back({});
        }
        
        levels[depth].push_back(node->val);
        dfs(node->left, depth + 1, levels);
        dfs(node->right, depth + 1, levels);
    }
};
