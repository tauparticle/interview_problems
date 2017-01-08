/*46. Permutations   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 139045
 Total Submissions: 344648
 Difficulty: Medium
 Contributors: Admin
 Given a collection of distinct numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 Hide Company Tags LinkedIn Microsoft
 Hide Tags Backtracking
 Hide Similar Problems (M) Next Permutation (M) Permutations II (M) Permutation Sequence (M) Combinations

 */


// resursive method using combination

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int>> results;
        if (num.size() == 0)
        {
            results.push_back(num);
            return results;
        }
        
        int prefix = num[0];
        vector<int> suffix(++num.begin(), num.end());
        vector<vector<int>> subPerm = permute(suffix);
        for(int i=0; i<subPerm.size(); ++i)
        {
            int len = subPerm[i].size();
            // insert prefix around every element in list
            for(int j=0; j<=len; ++j)
            {
                results.push_back(injectNumAtIndex(subPerm[i], prefix, j));
            }
        }
        return results;
    }
    
    vector<int> injectNumAtIndex(vector<int>& list, int num, int pos) {
        vector<int> ret;
        for (int i=0; i<pos; ++i) {
            ret.push_back(list[i]);
        }
        ret.push_back(num);
        
        for (int i=pos; i<list.size(); ++i) {
            ret.push_back(list[i]);
        }
        return ret;    }
};


// backtracking solution.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(nums, current, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& res)
    {
        if (current.size() == nums.size())
        {
            res.push_back(vector<int>(current.begin(), current.end()));
        }
        else
        {
            for (int i=0; i<nums.size(); ++i)
            {
                if (find(current.begin(), current.end(), nums[i]) != current.end())
                {
                    continue;
                }
                current.push_back(nums[i]);
                backtrack(nums, current, res);
                current.pop_back();
            }
        }
    }
};
