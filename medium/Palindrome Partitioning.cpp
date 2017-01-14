/*
 131. Palindrome Partitioning   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 83847
 Total Submissions: 271984
 Difficulty: Medium
 Contributors: Admin
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 Hide Company Tags Bloomberg
 Hide Tags Backtracking
 Hide Similar Problems (H) Palindrome Partitioning II

 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        backtrack(s, 0, current, res);
        return res;
    }
    
    void backtrack(string& s, int index, vector<string>& current, vector<vector<string>>& res)
    {
        if (index == s.size())
        {
            res.push_back(current);
            return;
        }
        else
        {
            for (int i=index; i<s.length(); ++i)
            {
                if (isPalindrome(s, index, i))
                {
                    current.push_back(s.substr(index, i-index+1));
                    backtrack(s, i+1, current, res);
                    current.pop_back();
                }
            }
        }
        
    }
    
    bool isPalindrome(string& str, int start, int end)
    {
        while (start < end)
        {
            if (str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }
};
