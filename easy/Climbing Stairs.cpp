/*
 70. Climbing Stairs   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 149683
 Total Submissions: 387051
 Difficulty: Easy
 Contributors: Admin
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Note: Given n will be a positive integer.
 
 Hide Company Tags Adobe Apple
 Hide Tags Dynamic Programming
*/

public class Solution {
    public int climbStairs(int n) {
        
        int first = 1;
        int second = 1;
        
        int count = 1;
        
        for (int i=2; i<=n; ++i)
        {
            count = first + second;
            second = first;
            first = count;
        }
        return count;
    }
}
