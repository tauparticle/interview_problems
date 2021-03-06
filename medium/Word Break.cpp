/*139. Word Break   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 123045
 Total Submissions: 435711
 Difficulty: Medium
 Contributors: Admin
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 
 UPDATE (2017/1/4):
 The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 
 Hide Company Tags Google Uber Facebook Amazon Yahoo Bloomberg Pocket Gems
 Hide Tags Dynamic Programming
 Hide Similar Problems (H) Word Break II
*/

class Solution {
public:
    
    // 2 ways of solving this.  One with a DP memo array.  O(n^2) time.
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i=1; i<=s.length(); ++i)
        {
            for (int j=0; j<i; j++)
            {
                if (!dp[j])
                {
                    continue;
                }
                string sub = s.substr(j, i-j);
                if (dict.find(sub) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    
    // second way is recursively partitioning the array until all sub-parts are in the dict.
    bool wordBreak_recursiveDP(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        
        return wordBreak(s, dict, memo);
    }
    
    bool wordBreak(string s, unordered_set<string>& dict, unordered_map<string, bool>& memo)
    {
        if (dict.find(s) != dict.end())
        {
            return true;
        }
        
        if (memo.find(s) != memo.end())
        {
            return memo[s];
        }
        
        for (int i=1; i<s.length(); ++i)
        {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end())
            {
                string suffix = s.substr(i);
                if (wordBreak(suffix, dict, memo))
                {
                    memo[s] = true;
                    return true;
                }
            }
        }
        memo[s] = false;
        return false;
    }
};
