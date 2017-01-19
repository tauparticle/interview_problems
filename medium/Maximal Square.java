/*
 221. Maximal Square   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 49920
 Total Submissions: 183883
 Difficulty: Medium
 Contributors: Admin
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 
 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.
 
 Hide Company Tags Apple Airbnb Facebook
 Hide Tags Dynamic Programming
 Hide Similar Problems (H) Maximal Rectangle

 */

public class Solution {
    public int maximalSquare(char[][] matrix) {
        
        if (matrix == null || matrix.length == 0)
        {
            return 0;
        }
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int[][] memo = new int[rows][cols];
        
        for (int row = 0; row < rows; ++row)
        {
            memo[row][0] = Character.getNumericValue(matrix[row][0]);
        }
        for (int col = 0; col < cols; ++col)
        {
            memo[0][col] = Character.getNumericValue(matrix[0][col]);
        }
        
        int maxSquare = 0;
        
        for (int row = 1; row < rows; ++row)
        {
            for (int col = 1; col < cols; ++col)
            {
                if (matrix[row][col] == '1')
                {
                    // find minimum of 3 other corners
                    int min = Math.min(memo[row-1][col], memo[row-1][col-1]);
                    min = Math.min(min, memo[row][col-1]);
                    memo[row][col] = min + 1;
                }
                else
                {
                    memo[row][col] = 0;
                }
            }
        }
        
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                maxSquare = Math.max(maxSquare, memo[row][col]);
            }
        }
        
        return maxSquare * maxSquare;
    }
}
