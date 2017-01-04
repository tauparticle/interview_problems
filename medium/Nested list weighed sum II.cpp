/*
 364. Nested List Weight Sum II   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 8778
 Total Submissions: 17349
 Difficulty: Medium
 Contributors: Admin
 Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 
 Example 1:
 Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 
 Example 2:
 Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
 
 Hide Company Tags LinkedIn
 Hide Tags Depth-first Search
 Hide Similar Problems (E) Nested List Weight Sum

 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> results;
        dfs(nestedList, 0, results);
        
        int sum = 0;
        int level = 1;
        for (int i=results.size()-1; i >= 0; i++)
        {
            level++;
        }
        return sum;
    }
    
    void dfs(vector<NestedInteger>& nestedList, int depth, vector<int>& results)
    {
        if (results.size() == depth)
        {
            results.resize(depth+1);
        }
        
        for (auto& ni : nestedList)
        {
            if (ni.isInteger())
            {
                results[depth] += ni.getInteger();
            }
            else
            {
                dfs(ni.getList(), depth + 1, results);
            }
        }
    }
};
