
/*
 461. Hamming Distance   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 24045
 Total Submissions: 33707
 Difficulty: Easy
 Contributors: Samuri
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 
 Given two integers x and y, calculate the Hamming distance.
 
 Note:
 0 ≤ x, y < 231.
 
 Example:
 
 Input: x = 1, y = 4
 
 Output: 2
 
 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
 ↑   ↑
 
 The above arrows point to positions where the corresponding bits are different.
 Hide Company Tags Facebook
 Hide Tags Bit Manipulation
 Hide Similar Problems (E) Number of 1 Bits (M) Total Hamming Distance

 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hammingDist = 0;
        
        for (int i=0; i<32; ++i)
        {
            int x_bit = x >> i & 1;
            int y_bit = y >> i & 1;
            if (x_bit ^ y_bit)
            {
                hammingDist++;
            }
        }
        return hammingDist;
    }
};
