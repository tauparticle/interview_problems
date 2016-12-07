/*
 Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 
 Note:
 The array size can be very large. Solution that uses too much extra space will not pass the judge.
 
 Example:
 
 int[] nums = new int[] {1,2,3,3,3};
 Solution solution = new Solution(nums);
 
 // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 solution.pick(3);
 
 // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 solution.pick(1);
 
 */

// this is classic resoviore sampling.
// https://en.wikipedia.org/wiki/Reservoir_sampling

class Solution {
public:
    Solution(vector<int> nums) {
        m_nums = nums;
    }
    
    int pick(int target)
    {
        
        int result = 0;
        int counter = 1;
        for(int i = 0; i < m_nums.size(); i++)
        {
            if(m_nums[i] == target)
            {
                if(rand() % counter == 0)
                {
                    result = i;
                }
                counter++;
            }
        }
        return result;
    }
    
private:
    vector<int> m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
