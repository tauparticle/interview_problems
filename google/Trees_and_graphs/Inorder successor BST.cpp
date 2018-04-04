/*Inorder Successor in BST
 Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 
 Note: If the given node has no in-order successor in the tree, return null.
 */

/*
 Notes:  This is how to find the predecesor and the successor for a given node in BST
 The inorder traversal of a BST is the nodes in ascending order. To find a successor, you just need to find the
 smallest one that is larger than the given value since there are no duplicate values in a BST. It just like the
 binary search in a sorted list. The time complexity should be O(h) where h is the depth of the result node.
 succ is a pointer that keeps the possible successor. Whenever you go left the current root is the new possible
 successor, otherwise the it remains the same.
 
 Only in a balanced BST O(h) = O(log n). In the worst case h can be as large as n.
 
 public TreeNode predecessor(TreeNode root, TreeNode p) {
    if (root == null)
        return null;
    
    if (root.val >= p.val) {
        return predecessor(root.left, p);
    } else {
        TreeNode right = predecessor(root.right, p);
        return (right != null) ? right : root;
    }
}

public TreeNode successor(TreeNode root, TreeNode p) {
    if (root == null)
        return null;
    
    if (root.val <= p.val) {
        return successor(root.right, p);
    } else {
        TreeNode left = successor(root.left, p);
        return (left != null) ? left : root;
    }
}
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if (!root || !p) return nullptr;
        
        TreeNode *suc = nullptr;
        while (root)
        {
            if (root->val <= p->val)
            {
                root = root->right;
            }
            else
            {
                suc = root;
                root = root->left;
            }
        }
        
        return suc;
    }
};
