/*
 Longest Common Prefix
 Write a function to find the longest common prefix string amongst an array of strings.
 */

class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxPrefixLen = INT_MAX;
        string prefix;
        if (strs.size() == 0)
        {
            return prefix;
        }
        for (const auto &s : strs)
        {
            maxPrefixLen = min(maxPrefixLen, (int)s.length());
        }
        
        for (int index=0; index<maxPrefixLen; ++index)
        {
            char current = strs[0][index];
            for (int i=1; i<strs.size(); ++i)
            {
                if (strs[i][index] != current)
                {
                    return prefix;
                }
            }
            
            prefix += current;
        }
        
        return prefix;
    }
};
