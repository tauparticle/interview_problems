/*296. Best Meeting Point
 Description  Submission  Solutions  Add to List
 Total Accepted: 10623
 Total Submissions: 20920
 Difficulty: Hard
 Contributors: Admin
 A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 
 For example, given three people living at (0,0), (0,4), and (2,2):
 
 1 - 0 - 0 - 0 - 1
 |   |   |   |   |
 0 - 0 - 0 - 0 - 0
 |   |   |   |   |
 0 - 0 - 1 - 0 - 0
 The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
 
 Hint:
 
 Try to solve it in one dimension first. How can this solution apply to the two dimension case?
 Hide Company Tags Twitter
 Hide Tags Math Sort
 Hide Similar Problems (H) Shortest Distance from All Buildings (M) Minimum Moves to Equal Array Elements II

 */

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        if (rows == 0)
        {
            return 0;
        }
        int cols = grid[0].size();
        int total = 0;
        
        // find all 1's and record their position
        vector<int> rowPos;
        vector<int> colPos;
        
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowPos.push_back(i);
                    colPos.push_back(j);
                }
            }
        }
        
        // rows are orderd, but columns will be out of order.  Find the median of the columns and the median of the rows.
        int medianRow = rowPos[rowPos.size() / 2];
        nth_element(colPos.begin(), colPos.begin() + colPos.size() / 2, colPos.end());
        int medianCol = colPos[colPos.size()/2];
        
        // loop through all row values and column values and sum up the difference between those values and the median
        for (int row : rowPos)
        {
            total += abs(row - medianRow);
        }
        for (int col : colPos)
        {
            total += abs(col - medianCol);
        }
        
        // return total sum
        return total;
        
    }
};
