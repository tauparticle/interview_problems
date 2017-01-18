// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
#include <iostream>


//"red blue red", "aba"  -> True
//"red red blue", "aab"   -> True
//"red red red", "aaa"   -> True
//"red red blue", "abc"  -> False
//"red blue green",  "aab"  -> False

using namespace std;


vector<string> parseLine(string& s)
{
    // return srings split by space
}

////// MY NOTES:  I got a correct, but inefficent solution.  Shit Fuck!

//"red blue red", "aba"  -> True   [[red, 2], [blue, 1]]   [[a, 2], [b, 1]]
//"red red blue", "aab"   -> True
//"red red red", "aaa"   -> True
//"red red blue", "abc"  -> False  [[red, 1], [blue, 2]]  [[a, 0], [b, 1], [c, 2]]
//"red blue green",  "aab"  -> False [red, 0], [blue, 1], [green, 2]] [[a,1], [b, 2]]

// red blue red red -> aaba   

red blue red blue  <-> baab  [[red, {0, 1}, [blue, {1, 3}]] -> [[b, {0, 3}, [a, {1, 2}]]]

bool checkPattern(string& words, string& pattern)
{
    
    auto wds =  parseLine(words);
    
    if (wds.size() != pattern.length())
    {
        return false;
    }
    
    // build up our maps of word to index
    
    unorderd_map<word, vector<int>> wordIndex;
    unorderd_map<char, pair<int, int>> patternIndex;
    
    for (int i=0; i<wds.size(); ++i)
    {
       auto& list = wordIndex[wds[i]];
       list.push_back(i);
       auto& pat_list = patternIndex[pattern[i]];
       pat_list.push_back(i);
    }
    
    if (wordIndex.size() != patternIndex.size()) return false;
    
    for (int i=0; i<wds.size(); ++i)
    {
        if (!compareVectors(wordIndex[wds[i]], patternIndex[pattern[i]]))
        {
            return false;
        }
    }
    
    return true;
}

bool compareVectors(vector<int>& a, vector<int>& b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    
    for (int i=0; i<a.size(); ++i)
    {
        if (a[i] = b[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}