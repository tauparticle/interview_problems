/*
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 */
class Solution {
    public:
    int strStr(string haystack, string needle) {
        
        for (int i=0; ;i++)
        {
            for (int j=0; ;j++)
            {
                if (j == needle.length())
                {
                    return i;
                }
                
                if (j + i == haystack.length())
                {
                    return -1;
                }
                
                if (haystack[i+j] != needle[j])
                {
                    break;
                }
            }
        }
    }
};
