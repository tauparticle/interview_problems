/*
 32. Longest Valid Parentheses   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 84807
 Total Submissions: 367057
 Difficulty: Hard
 Contributors: Admin
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 
 Hide Tags Dynamic Programming String
 Hide Similar Problems (E) Valid Parentheses

 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1);
        for (int i=0; i<s.length(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};
