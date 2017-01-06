
/*
 254. Factor Combinations   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 18845
 Total Submissions: 46802
 Difficulty: Medium
 Contributors: Admin
 Numbers can be regarded as product of its factors. For example,
 
 8 = 2 x 2 x 2;
 = 2 x 4.
 Write a function that takes an integer n and return all possible combinations of its factors.
 
 Note:
 You may assume that n is always positive.
 Factors should be greater than 1 and less than n.
 Examples:
 input: 1
 output:
 []
 input: 37
 output:
 []
 input: 12
 output:
 [
 [2, 6],
 [2, 2, 3],
 [3, 4]
 ]
 input: 32
 output:
 [
 [2, 16],
 [2, 2, 8],
 [2, 2, 2, 4],
 [2, 2, 2, 2, 2],
 [2, 4, 4],
 [4, 8]
 ]
 Hide Company Tags LinkedIn Uber
 Hide Tags Backtracking
 Hide Similar Problems (M) Combination Sum
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> results;
        vector<int> tmp;
        backtrace(n, 2, tmp, results);
        return results;
    }
    
    void backtrace(int n, int start, vector<int> tmp, vector<vector<int>>& results)
    {
        if (n <= 1)
        {
            if (tmp.size() > 1)
            {
                results.push_back(tmp);
            }
            return;
        }
        
        for (int i=start; i<=n; ++i)
        {
            if (n % i == 0)
            {
                tmp.push_back(i);
                backtrace(n / i, i, tmp, results);
                tmp.resize(tmp.size()-1);
            }
        }
    }
};
