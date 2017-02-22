/*
 340. Longest Substring with At Most K Distinct Characters
 Description  Submission  Solutions  Add to List
 Total Accepted: 17463
 Total Submissions: 45397
 Difficulty: Hard
 Contributors: Admin
 Given a string, find the length of the longest substring T that contains at most k distinct characters.
 
 For example, Given s = “eceba” and k = 2,
 
 T is "ece" which its length is 3.
 
 Hide Company Tags Google
 Hide Tags Hash Table String
 Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters (M) Longest Repeating Character Replacement

 */

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        int tail = 0;
        unordered_map<char, int> window;
        
        for (int i=0; i<s.length(); ++i)
        {
            window[s[i]]++;
            
            while (window.size() > k)
            {
                window[s[tail]]--;
                if (window[s[tail]] == 0)
                {
                    window.erase(s[tail]);
                }
                tail++;
            }
            
            maxLen = max(maxLen, i-tail+1);
        }
        
        return maxLen;
    }
};
