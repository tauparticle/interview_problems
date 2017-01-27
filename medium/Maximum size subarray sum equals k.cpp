/*
 325. Maximum Size Subarray Sum Equals k   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 19542
 Total Submissions: 46863
 Difficulty: Medium
 Contributors: Admin
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 
 Note:
 The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
 
 Example 1:
 Given nums = [1, -1, 5, -2, 3], k = 3,
 return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 
 Example 2:
 Given nums = [-2, -1, 2, 1], k = 1,
 return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
 
 Follow Up:
 Can you do it in O(n) time?
 
 Hide Company Tags Palantir Facebook
 Hide Tags Hash Table
 Hide Similar Problems (M) Minimum Size Subarray Sum (E) Range Sum Query - Immutable
*/

class Solution {
public:
    
    // O(N) runtime, O(n) space
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        // as we traverse, compute sum from i=0 -> i=n and keep the sum in a hashmap<value, i>
        // Keep track of length as you go
        
        int current_sum = 0;
        int max_length = 0;
        unordered_map<int, int> sums;
        
        for (int i=0; i<nums.size(); i++)
        {
            // update current sum
            current_sum += nums[i];
            
            // if current sum == k, max_length = i+1;
            if (current_sum == k)
            {
                max_length = i + 1;
            }
            else if (sums.find(current_sum - k) != sums.end())
            {
                // difference has been computed previously, compute if range sum yields
                // larger length;
                max_length = max(max_length, i - sums[current_sum - k]);
            }
            
            if (sums.find(current_sum) == sums.end())
            {
                // current sum doesn't exist, add range sum to map
                sums[current_sum] = i;
            }
        }
        
        return max_length;
    }
    
};
