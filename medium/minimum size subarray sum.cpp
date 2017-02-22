/*
 209. Minimum Size Subarray Sum Add to List
 Description  Submission  Solutions
 Total Accepted: 70467
 Total Submissions: 242042
 Difficulty: Medium
 Contributors: Admin
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 
 click to show more practice.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 
 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.
 
 Hide Company Tags Facebook
 Hide Tags Array Two Pointers Binary Search
 Hide Similar Problems (H) Minimum Window Substring (M) Maximum Size Subarray Sum Equals k

 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int firstPos = 0, sum = 0, minLength = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minLength = min(minLength, i - firstPos + 1);
                sum -= nums[firstPos++];
            }
        }
        
        return minLength == INT_MAX? 0 : minLength;
    }
};
