/*
 Rotate Array
 Rotate an array of n elements to the right by k steps.
 
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 
 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 
 [show hint]
 
 Hint:
 Could you do it in-place with O(1) extra space?
 Related problem: Reverse Words in a String II
*/

class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        k = k > nums.size() ? k % nums.size() : k;
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
        
    }
    
    void reverse(vector<int>& nums, int left, int right)
    {
        while (left >= 0 && right < nums.size() && left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
};
