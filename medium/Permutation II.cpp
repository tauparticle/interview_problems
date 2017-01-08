/*
 47. Permutations II   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 100313
 Total Submissions: 324223
 Difficulty: Medium
 Contributors: Admin
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 
 For example,
 [1,1,2] have the following unique permutations:
 [
 [1,1,2],
 [1,2,1],
 [2,1,1]
 ]
 Hide Company Tags LinkedIn Microsoft
 Hide Tags Backtracking
 Hide Similar Problems (M) Next Permutation (M) Permutations (M) Palindrome Permutation II

 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, current, res, used);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& results, vector<bool>& used)
    {
        if (current.size() == nums.size())
        {
            results.push_back(vector<int>(current.begin(), current.end()));
        }
        else
        {
            for(int i=0; i<nums.size(); ++i)
            {
                // check if i has been used already, or if previous value is equal to current and or previous was not already used
                if (used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1])
                {
                    continue;
                }
                
                // mark as used & back track
                used[i] = true;
                current.push_back(nums[i]);
                
                backtrack(nums, current, results, used);
                
                used[i] = false;
                current.pop_back();
            }
        }
    }
};
