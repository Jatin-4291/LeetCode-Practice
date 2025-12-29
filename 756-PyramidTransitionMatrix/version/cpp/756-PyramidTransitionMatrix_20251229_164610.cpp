// Last updated: 12/29/2025, 4:46:10 PM
1class Solution {
2    // Map to store allowed transitions
3    // Key: pair of characters (length 2)
4    // Value: list of possible characters on top
5    unordered_map<string, vector<char>> mpp;
6
7public:
8    // DFS function to try building pyramid
9    // bot -> current bottom row
10    // i   -> current index in bot
11    // tem -> temporary string for next row
12    bool dfs(string bot, int i, string tem) {
13        
14        // Base case: pyramid successfully built
15        if (bot.size() == 1) 
16            return true;
17
18        // If we finished building the next row
19        if (i == bot.size() - 1) {
20            string nextRow;
21            return dfs(tem, 0, nextRow);
22        }
23
24        // Take current adjacent pair
25        string key = bot.substr(i, 2);
26
27        // Try all possible characters that can go above this pair
28        for (char v : mpp[key]) {
29            tem.push_back(v);              // choose
30            if (dfs(bot, i + 1, tem))      // explore
31                return true;               // valid pyramid found
32            tem.pop_back();                // backtrack
33        }
34
35        // No valid configuration found
36        return false;
37    }
38
39    bool pyramidTransition(string bottom, vector<string>& allowed) {
40        
41        // Build the mapping from allowed transitions
42        for (auto &a : allowed) {
43            mpp[a.substr(0, 2)].push_back(a[2]);
44        }
45
46        string temp;
47        return dfs(bottom, 0, temp);
48    }
49};