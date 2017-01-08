/*
 Design a data structure that supports all following operations in average O(1) time.
 
 insert(val): Inserts an item val to the set if not already present.
 remove(val): Removes an item val from the set if present.
 getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 Example:
 
 // Init an empty set.
 RandomizedSet randomSet = new RandomizedSet();
 
 // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 randomSet.insert(1);
 
 // Returns false as 2 does not exist in the set.
 randomSet.remove(2);
 
 // Inserts 2 to the set, returns true. Set now contains [1,2].
 randomSet.insert(2);
 
 // getRandom should return either 1 or 2 randomly.
 randomSet.getRandom();
 
 // Removes 1 from the set, returns true. Set now contains [2].
 randomSet.remove(1);
 
 // 2 was already in the set, so return false.
 randomSet.insert(2);
 
 // Since 1 is the only number in the set, getRandom always return 1.
 randomSet.getRandom();
 
 */

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        // check if value exists.  Return false if it exists
        auto iter = m_map.find(val);
        if (iter != m_map.end())
        {
            return false;
        }
        
        // Add it to our vector and insert it into our map
        m_keys.push_back(val);
        m_map[val] = m_keys.size()-1;;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        // check if exists.  If not return false.
        auto iter = m_map.find(val);
        if (iter == m_map.end())
        {
            return false;
        }
        
        // else swap the element in the vector with the end element, update the swapped index value,
        // and pop the back element from the vector
        int itemIndex = iter->second;
        int last = m_keys.back();
        m_keys[itemIndex] = last;
        m_map[last] = itemIndex;
        m_keys.pop_back();
        
        
        // then erase the element from the map.
        m_map.erase(iter);
        return true;
    }
    
    
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % m_keys.size();
        return m_keys[index];
    }
    
private:
    
    unordered_map<int, int> m_map;  // value to index
    vector<int> m_keys;  // list of keys
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
