/*136. Single Number   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 183931
Total Submissions: 348750
Difficulty: Easy
Contributors: Admin
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Hide Company Tags Palantir Airbnb
Hide Tags Hash Table Bit Manipulation
Hide Similar Problems (M) Single Number II (M) Single Number III (M) Missing Number (H) Find the Duplicate Number (E) Find the Difference
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oddManOut =0;
        for (int i : nums)
        {
            oddManOut ^= i;
        }
        return oddManOut;
    }
};
