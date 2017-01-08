/*1. Two Sum   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 389830
 Total Submissions: 1308499
 Difficulty: Easy
 Contributors: Admin
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 UPDATE (2016/2/13):
 The return format had been changed to zero-based indices. Please read the above updated description carefully.
 
 Hide Company Tags LinkedIn Uber Airbnb Facebook Amazon Microsoft Apple Yahoo Dropbox Bloomberg Yelp Adobe
 Hide Tags Array Hash Table
 Hide Similar Problems (M) 3Sum (M) 4Sum (M) Two Sum II - Input array is sorted (E) Two Sum III - Data structure design

 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res = {-1, -1};
        unordered_map<int, int> map;
        
        for (int i=0; i<nums.size(); ++i)
        {
            int diff = target - nums[i];
            auto iter = map.find(diff);
            if (iter != map.end())
            {
                res = {i, iter->second};
                break;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};
