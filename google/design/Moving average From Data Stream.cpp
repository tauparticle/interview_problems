/*Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_sum = 0.0;
        m_size = size;
    }
    
    double next(int val) {
        
        if (m_buffer.size() == m_size)
        {
            // pop back and remove
            m_sum -= m_buffer.back();
            m_buffer.pop_back();
        }
        
        m_sum += val;
        m_buffer.push_front(val);
        return m_sum / m_buffer.size();
        
    }
private:
    
    list<int> m_buffer;
    double m_sum;
    int m_size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
