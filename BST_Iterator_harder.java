/*
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 
 Calling next() will return the next smallest number in the BST.
 
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    
    private TreeNode currentNode;
    private Stack<TreeNode> parents = new Stack<TreeNode>();
    public BSTIterator(TreeNode root) {
        this.currentNode = root;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return this.inorderSucc(this.currentNode) != null;
    }
    
    /** @return the next smallest number */
    public int next() {
        this.currentNode = this.inorderSucc(this.currentNode);
        return this.currentNode.val;
    }
    
    private TreeNode inorderSucc(TreeNode n)
    {
        if (n == null) {
            return null;
        }
        
        if (n.right != null) {
            // found right children.  Return leftmost node of right
            return leftMostChild(n.right);
        }
        else {
            TreeNode q = n;
            TreeNode x = parents.peek();
            parents.pop();
            // go up until we're on the left instead of right
            while(x != null && x.left != q) {
                q = x;
                x = parents.peek();
                parents.pop();
            }
            
            return x;
        }
    }
    
    private TreeNode leftMostChild(TreeNode n)
    {
        if (n == null) {
            return null;
        }
        
        while (n.left != null) {
            // push the parents on a stack for backtracking
            parents.push(n);
            n = n.left;
        }
        
        return n;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */