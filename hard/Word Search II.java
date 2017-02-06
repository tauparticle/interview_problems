/*212. Word Search II
Description  Submission  Solutions  Add to List
Total Accepted: 37504
Total Submissions: 166994
Difficulty: Hard
Contributors: Admin
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

Hide Company Tags Microsoft Google Airbnb
Hide Tags Backtracking Trie
Hide Similar Problems (M) Word Search
*/


public class Solution {
    
    public class TrieNode
    {
        public TrieNode[] children;
        public boolean isLeaf;
        
        public TrieNode() {
            this.children = new TrieNode[26];
            this.isLeaf = false;
        }
    }
    
    public class Trie
    {
        public TrieNode root;
        
        public Trie()
        {
            this.root = new TrieNode();
        }
        
        public void Add(String str)
        {
            TrieNode child = this.root;
            TrieNode[] children = child.children;
            for (int i=0; i<str.length(); ++i)
            {
                int idx = str.charAt(i) - 'a';
                if (children[idx] == null)
                {
                    child = new TrieNode();
                    children[idx] = child;
                }
                else
                {
                    child = children[idx];
                }
                children = child.children;
                if (i == str.length()-1)
                {
                    child.isLeaf = true;
                }
            }
        }
        
        public boolean SearchPrefix(String str)
        {
            return this.Search(str, false);
        }
        
        public boolean SearchWord(String str)
        {
            return this.Search(str, true);
        }
        
        private boolean Search(String str, boolean leafRequired)
        {
            TrieNode child = this.root;
            TrieNode[] children = child.children;
            for (int i=0; i<str.length(); ++i)
            {
                int idx = str.charAt(i) - 'a';
                if (children[idx] == null)
                {
                    return false;
                }
                
                child = children[idx];
                children = child.children;
            }
            
            return leafRequired ? child.isLeaf : true;
        }
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        
        HashSet<String> results = new HashSet<String>();
        
        Trie trie = new Trie();
        for (String word : words)
        {
            trie.Add(word);
        }
        
        StringBuilder sb = new StringBuilder();
        
        for (int row = 0; row < board.length; ++row)
        {
            for (int col = 0; col < board[0].length; ++col)
            {
                backtrack(board, row, col, sb, trie, results);
            }
        }
        
        return new ArrayList<String>(results);
    }
    
    private int[][] directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    private void backtrack(char[][] board, int row, int col, StringBuilder current, Trie trie, HashSet<String> results)
    {
        if (row < 0 ||                  // out of bouds
            row >= board.length ||      // out of bounds
            col < 0 ||                  // out of bounds
            col >= board[0].length ||   // out of bounds
            board[row][col] == '#' ||   // already visited
            !trie.SearchPrefix(current.toString())) // not a prefix match of any word
        {
            return;
        }
        
        char c = board[row][col];
        current.append(c);
        board[row][col] = '#'; // mark as visiting
        
        String currentWord = current.toString();
        if (trie.SearchWord(currentWord))
        {
            results.add(currentWord);
        }
        
        // visit each direction
        for (int dir = 0; dir < directions.length; ++dir)
        {
            backtrack(board, row + directions[dir][0], col + directions[dir][1], current, trie, results);
        }
       
        // mark as unvisited
        board[row][col] = c;
        current.deleteCharAt(current.length()-1);
    }
}