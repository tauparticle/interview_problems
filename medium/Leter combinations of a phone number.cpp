/*
 17. Letter Combinations of a Phone Number   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 125139
 Total Submissions: 382887
 Difficulty: Medium
 Contributors: Admin
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 
 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 
 Hide Company Tags Amazon Dropbox Google Uber Facebook
 Hide Tags Backtracking String
 Hide Similar Problems (M) Generate Parentheses (M) Combination Sum (E) Binary Watch
*/


class Solution {
public:
    
    struct PhoneNode
    {
        string word;
        int count;
        PhoneNode(string w, int c)
        {
            word = w;
            count = c;
        }
    };
    
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<string>> mapping = {{'2', {"a","b","c"}},
            {'3', {"d","e","f"}},
            {'4', {"g","h","i"}},
            {'5', {"j","k","l"}},
            {'6', {"m","n","o"}},
            {'7', {"p","q","r","s"}},
            {'8', {"t","u","v"}},
            {'9', {"w","x","y","z"}}};
        
        stack<PhoneNode> s;
        vector<string> ret;
        if (digits.length() == 0)
        {
            return ret;
        }
        
        vector<string>& strs = mapping[digits[0]];
        for (auto c : strs)
        {
            PhoneNode n(c, 1);
            s.push(n);
        }
        
        while (!s.empty())
        {
            PhoneNode n = s.top();
            s.pop();
            
            if (n.count == digits.size())
            {
                ret.push_back(n.word);
            }
            else
            {
                vector<string>& chars = mapping[digits[n.count]];
                for (auto c : chars)
                {
                    PhoneNode newNode(n.word + c, n.count + 1);
                    s.push(newNode);
                }
            }
        }
        return ret;
        
    }
};
