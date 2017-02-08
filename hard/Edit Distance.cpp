/*
 72. Edit Distance
 Description  Submission  Solutions  Add to List
 Total Accepted: 78397
 Total Submissions: 255016
 Difficulty: Hard
 Contributors: Admin
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
 Hide Tags Dynamic Programming String
 Hide Similar Problems (M) One Edit Distance

 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length()+1, vector<int>(word2.length()+1, -1));
        return minDistance(word1, word2, word1.length(), word2.length(), memo);
    }
    
    int minDistance(string& word1, string& word2, int n, int m, vector<vector<int>>& memo)
    {
        if (memo[n][m] != -1)
        {
            return memo[n][m];
        }
        
        if (n == 0)
        {
            return m;
        }
        
        if (m == 0)
        {
            return n;
        }
        
        if (word1[n-1] == word2[m-1])
        {
            return minDistance(word1, word2, n-1, m-1, memo);
        }
        else
        {
            int insert = minDistance(word1, word2, n-1, m, memo);
            int del = minDistance(word1, word2, n, m-1, memo);
            int edit = minDistance(word1, word2, n-1, m-1, memo);
            int total = 1 + min(min(insert, del), edit);
            memo[n][m] = total;
            return total;
        }
    }
};
