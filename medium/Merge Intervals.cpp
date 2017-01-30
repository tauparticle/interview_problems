/*
 56. Merge Intervals   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 102365
 Total Submissions: 358099
 Difficulty: Medium
 Contributors: Admin
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 
 Hide Company Tags LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
 Hide Tags Array Sort
 Hide Similar Problems (H) Insert Interval (E) Meeting Rooms (M) Meeting Rooms II

 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    struct IntervalSort
    {
        
        bool operator()(const Interval& a, const Interval& b)
        {
            if (a.start == b.start)
            {
                return a.end < b.end;
            }
            return a.start < b.start;
        }
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), IntervalSort());
        
        vector<Interval> result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            Interval& current = intervals[i];
            Interval& prev = result.back();
            
            if (prev.end < current.start)
            {
                result.push_back(current);
            }
            else
            {
                prev.end = max(prev.end, current.end);
            }
        }
        return result;
    }
};
