/*
 79. Word Search
 Description  Submission  Discussion  Add to List
 Total Accepted: 108604
 Total Submissions: 425940
 Difficulty: Medium
 Contributors: Admin
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 Hide Company Tags Microsoft Bloomberg Facebook
 Hide Tags Array Backtracking
 Hide Similar Problems (H) Word Search II

 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        vector<char> current;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (backtrack(board, row, col, word, current))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    
    bool isPrefixMatch(string& word, vector<char>& current)
    {
        for (int i=0; i<current.size(); ++i)
        {
            if (word[i] != current[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board, int row, int col, string& word, vector<char>& current)
    {
        if (row < 0 ||
            row >= board.size() ||
            col < 0 ||
            col >= board[0].size() ||
            current.size() > word.length() ||
            board[row][col] == '#')
        {
            return false;
        }
        
        // check current prefix for a match before continuing
        if (!isPrefixMatch(word, current))
        {
            return false;
        }
        
        char c = board[row][col];
        board[row][col] = '#';
        current.push_back(c);
        
        if (current.size() == word.length()  && strcmp(word.c_str(), string(current.data(), current.size()).c_str()) == 0)
        {
            return true;
        }
        
        for (int dir = 0; dir < m_directions.size(); ++dir)
        {
            if (backtrack(board, row + m_directions[dir][0], col + m_directions[dir][1], word, current))
            {
                return true;
            }
        }
        current.pop_back();
        board[row][col] = c;
        return false;
    }
    
    vector<vector<int>> m_directions = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
};
