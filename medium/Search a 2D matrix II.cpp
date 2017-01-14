/*
 240. Search a 2D Matrix II   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 62272
 Total Submissions: 164171
 Difficulty: Medium
 Contributors: Admin
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.
 For example,
 
 Consider the following matrix:
 
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 
 Given target = 20, return false.
 
 Hide Company Tags Amazon Google Apple
 Hide Tags Binary Search Divide and Conquer
 Hide Similar Problems (M) Search a 2D Matrix
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0)
        {
            return false;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0)
        {
            int val = matrix[row][col];
            if (val == target)
            {
                return true;
            }
            else if (val > target)
            {
                // decrement column
                col--;
            }
            else
            {
                // increment row
                row++;
            }
        }
        return false;
    }
    
    
};
