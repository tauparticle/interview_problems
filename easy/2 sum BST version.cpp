/*
 Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
 
 Example 1:
 Input:
 5
 / \
 3   6
 / \   \
 2   4   7
 
 Target = 9
 
 Output: True
 Example 2:
 Input:
 5
 / \
 3   6
 / \   \
 2   4   7
 
 Target = 28
 
 Output: False
 */


// Runtime O(n).  Memory O(n)
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int left = 0;
        int right = nums.size()-1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
