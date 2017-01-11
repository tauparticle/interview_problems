/*251. Flatten 2D Vector   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 19565
Total Submissions: 50471
Difficulty: Medium
Contributors: Admin
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Show Hint 
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Hide Company Tags Google Airbnb Twitter Zenefits
Hide Tags Design
Hide Similar Problems (M) Binary Search Tree Iterator (M) Zigzag Iterator (M) Peeking Iterator (M) Flatten Nested List Iterator
*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) 
        : m_data(vec2d)
        , m_row(0)
        , m_col(0)
    {
    }

    int next() {
        return m_data[m_row][m_col++];
     
    }

    bool hasNext() {
          // if at the end of a col, advanced to next row and reset col to zero
          while (m_row < m_data.size() && m_col == m_data[m_row].size())
          {
              m_row++;
              m_col = 0;
          }
          
          return m_row < m_data.size();
    }

private:
    vector<vector<int>> m_data;
    int m_row;
    int m_col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */