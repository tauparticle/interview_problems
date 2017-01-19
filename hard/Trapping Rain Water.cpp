/*42. Trapping Rain Water   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 95926
 Total Submissions: 271540
 Difficulty: Hard
 Contributors: Admin
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 
 
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 
 Show Company Tags
 Hide Tags Array Stack Two Pointers
 Hide Similar Problems (M) Container With Most Water (M) Product of Array Except Self (H) Trapping Rain Water II
 Have you met this question in a real interview? Yes
 */

public class Solution {
    
    // this is essentially a divide and conquer algo that finds the tallest bar, and then compute the volume of the subgraphs
    // on both sides of that bar.
    
    // O(n^2) runtime in the worst case to find the next tallest bar.  This can be optimized with pre-computing and storing
    // in a table.
    public int trap(int[] height) {
        int start = 0;
        int end = height.length - 1;
        
        int max = findIndexOfMax(height, start, end);
        int leftVolume = subgraphVolume(height, start, max, true);
        int rightVolume = subgraphVolume(height, max, end, false);
        return leftVolume + rightVolume;
    }
    
    int subgraphVolume(int[] height, int start, int end, boolean isLeft)
    {
        if (start >= end)
        {
            return 0;
        }
        int sum = 0;
        if (isLeft)
        {
            int max = findIndexOfMax(height, start, end-1);
            sum += borderedVolume(height, max, end);
            sum += subgraphVolume(height, start, max, isLeft);
        }
        else
        {
            int max = findIndexOfMax(height, start + 1, end);
            sum += borderedVolume(height, start, max);
            sum += subgraphVolume(height, max, end, isLeft);
        }
        return sum;
    }
    
    int findIndexOfMax(int[] height, int start, int end)
    {
        int indexOfMax = start;
        for (int i=start + 1; i <= end; ++i)
        {
            if (height[i] > height[indexOfMax])
            {
                indexOfMax = i;
            }
        }
        return indexOfMax;
    }
    
    int borderedVolume(int[] height, int start, int end)
    {
        if (start >= end)
        {
            return 0;
        }
        
        int min = Math.min(height[start], height[end]);
        int sum = 0;
        for (int i=start+1; i < end; i++)
        {
            sum += min - height[i];
        }
        return sum;
    }
}
