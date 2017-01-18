/*
149. Max Points on a Line   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 72707
Total Submissions: 466551
Difficulty: Hard
Contributors: Admin
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Hide Company Tags LinkedIn Apple Twitter
Hide Tags Hash Table Math
Hide Similar Problems (M) Line Reflection
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        // need to compare each point with all other points in sequence O(n^2) and O(n) space
        // 1)  If point is idential to another, count it as a special case.
        // 2)  else If the x values are the same, the line is vertical.  Use INT_MAX for the slope
        // 3)  else, compute slope and add it to a map.
        // Points are on the same line if the slope is the same.
        // Track the point counts per slope for each inner loop and remember to add the same points to the sum.
        
        int maxPoints = 0;
        
        if (points.size() == 1)
        {
            return 1;
        }
        
        for (int i=0; i<points.size(); ++i)
        {
            unordered_map<double, int> pointCounts;
            int overlappedPoints = 1; // include self
            for (int j=i+1; j<points.size(); ++j)
            {
                auto& p1 = points[i];
                auto& p2 = points[j];
                
                if (p1.x == p2.x && p1.y == p2.y)
                {
                    overlappedPoints++;
                }
                else if (p1.x == p2.x)
                {
                    // vertical line (infinite slope)
                    pointCounts[INT_MAX]++;
                }
                else
                {
                    // compute slope
                    double slope = double(p1.y - p2.y) / double(p1.x - p2.x);
                    pointCounts[slope]++;
                }
                
            }
            
            int localMax = 0;
            for (auto iter = pointCounts.begin(); iter != pointCounts.end(); ++iter)
            {
                localMax = max(localMax, iter->second);
            }
            localMax += overlappedPoints;
            maxPoints = max(maxPoints, localMax);
        }
        
        return maxPoints;
            
    }

}; 