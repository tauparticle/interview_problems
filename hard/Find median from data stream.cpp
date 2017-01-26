/*295. Find Median from Data Stream   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 33498
 Total Submissions: 142744
 Difficulty: Hard
 Contributors: Admin
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Design a data structure that supports the following two operations:
 
 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.
 For example:
 
 addNum(1)
 addNum(2)
 findMedian() -> 1.5
 addNum(3)
 findMedian() -> 2
 Credits:
 Special thanks to @Louis1992 for adding this problem and creating all test cases.
 
 Hide Company Tags Google
 Hide Tags Heap Design
 Hide Similar Problems (H) Sliding Window Median
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (m_maxHeap.empty() && m_minHeap.empty())
        {
            // add to max heap
            m_maxHeap.push(num);
        }
        else if (m_maxHeap.size() > m_minHeap.size())
        {
            if (num < m_maxHeap.top())
            {
                // add max heap top to min heap
                m_minHeap.push(m_maxHeap.top());
                m_maxHeap.pop();
                // add element to max heap
                m_maxHeap.push(num);
            }
            else
            {
                // add to min heap
                m_minHeap.push(num);
            }
        }
        else if (m_minHeap.size() > m_maxHeap.size())
        {
            if (num > m_minHeap.top())
            {
                // add min heap top to max heap
                m_maxHeap.push(m_minHeap.top());
                m_minHeap.pop();
                // add to min heap
                m_minHeap.push(num);
            }
            else
            {
                // add to max heap
                m_maxHeap.push(num);
            }
        }
        else
        {
            // if both heaps are the same size and not empty
            if (num > m_maxHeap.top())
            {
                // add to min heap
                m_minHeap.push(num);
            }
            else
            {
                // add to max heap
                m_maxHeap.push(num);
            }
        }
    }
    
    void swapElements()
    {
        int tmp = m_maxHeap.top();
        m_maxHeap.pop();
        m_maxHeap.push(m_minHeap.top());
        m_minHeap.pop();
    }
    
    double findMedian() {
        
        if (m_minHeap.size() == 0 && m_maxHeap.size() == 0)
        {
            return 0.0;
        }
        if (m_minHeap.size() > m_maxHeap.size())
        {
            return (double)m_minHeap.top();
        }
        else if(m_maxHeap.size() > m_minHeap.size())
        {
            return (double)m_maxHeap.top();
        }
        else
        {
            return (m_maxHeap.top() + m_minHeap.top()) / 2.0;
        }
    }
    
private:
    
    // min heap for top half
    priority_queue<int, vector<int>, std::greater<int>> m_minHeap;
    // max heap for bottom half
    priority_queue<int, vector<int>> m_maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
