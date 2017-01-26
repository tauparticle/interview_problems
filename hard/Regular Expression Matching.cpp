
/*
 Regular Expression Matching   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 117711
 Total Submissions: 498330
 Difficulty: Hard
 Contributors: Admin
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 Hide Company Tags Google Uber Airbnb Facebook Twitter
 Hide Tags Dynamic Programming Backtracking String
 Hide Similar Problems (H) Wildcard Matching
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p)
    {
        assert(s && p);
        if (*p == '\0') return *s == '\0';
        
        // next char is not '*': must match current character
        if (*(p+1) != '*')
        {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s, p+2))
            {
                return true;
            }
            s++;
        }
        return isMatch(s, p+2);
        
    }
};
