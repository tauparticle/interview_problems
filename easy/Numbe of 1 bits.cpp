/*191. Number of 1 Bits   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 128680
 Total Submissions: 334553
 Difficulty: Easy
 Contributors: Admin
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 
 Hide Company Tags Microsoft Apple
 Hide Tags
 
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int ones = 0;
        while (n)
        {
            if (n & 1 == 1)
            {
                ones++;
            }
            
            n >>= 1;
        }
        return ones;
    }
};
