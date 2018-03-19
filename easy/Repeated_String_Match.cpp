/*
 Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
 
 For example, with A = "abcd" and B = "cdabcdab".
 
 Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 
 Note:
 The length of A and B will be between 1 and 10000.
 
*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        string a_str = A;
        int loop = 1;
        
        // find minimum loop count because length of A must be at least equal to A
        while (a_str.length() < B.length())
        {
            loop++;
            a_str += A;
        }
        
        // see if B is in A
        if (a_str.find(B) != std::string::npos)
        {
            return loop;
        }
        
        // special case for overlap if start of B begins at the end of A
        a_str += A;
        if (a_str.find(B) != std::string::npos)
        {
            return loop + 1;
        }
        
        // not found
        return -1;
        
    }
};
