/*
 480. Sliding Window Median   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 2118
 Total Submissions: 6732
 Difficulty: Hard
 Contributors: YutingLiu
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
 
 For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 
 Window position                Median
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 
 Note:
 You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 
 Hide Company Tags Google
 Hide Similar Problems (H) Find Median from Data Stream

 */

class Solution {
public:
    
    /* The idea is to maintain a BST of the window and just search for the k/2 largest element and k/2 smallest element then the average of these two is the median of the window.
     
     Now if the STL's multiset BST maintained how many element were in each subtree finding each median would take O(log k) time but since it doesn't it takes O(k) time to find each median.
     */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> ret;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (window.size() < k)  continue;
            auto it1 = window.begin(), it2 = it1;
            advance(it1, (k-1)/2);
            it2 = it1;
            advance(it2, (k & 1) == 0);
            ret.push_back((long(*it1) + *it2) / 2.0);
            window.erase(window.find(nums[i-k+1]));
        }
        return ret;
    }
};
