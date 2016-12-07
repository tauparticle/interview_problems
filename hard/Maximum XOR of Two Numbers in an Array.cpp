/*421. Maximum XOR of Two Numbers in an Array   QuestionEditorial Solution  My Submissions
Total Accepted: 758
Total Submissions: 3062
Difficulty: Medium
Contributors: shen5630
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
Hide Company Tags Google
Hide Tags Bit Manipulation Trie

*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        unordered_set<int> t;
        // search from left to right, find out for each bit is there 
        // two numbers that has different value
        for (int i = 31; i >= 0; i--){
            // mask contains the bits considered so far
            mask |= (1 << i);
            t.clear();
            // store prefix of all number with right i bits discarded
            for (int n: nums){
                t.insert(mask & n);
            }
            
            // now find out if there are two prefix with different i-th bit
            // if there is, the new max should be current max with one 1 bit at i-th position, which is candidate
            // and the two prefix, say A and B, satisfies:
            // A ^ B = candidate
            // so we also have A ^ candidate = B or B ^ candidate = A
            // thus we can use this method to find out if such A and B exists in the set 
            int candidate = max | (1<<i);
            for (int prefix : t){
                if (t.find(prefix ^ candidate) != t.end()){
                    max = candidate;
                    break;
                }
                
            }
        }
        return max;
    }
};