/*
 Spiral Matrix
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        
        while(true)
        {
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            top++;
            if(left > right || top > bottom) break;
            
            for(int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            right--;
            if(left > right || top > bottom) break;
            
            for(int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
            bottom--;
            if(left > right || top > bottom) break;
            
            for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
            left++;
            if(left > right || top > bottom) break;
        }
        
        return res;
    }
};
