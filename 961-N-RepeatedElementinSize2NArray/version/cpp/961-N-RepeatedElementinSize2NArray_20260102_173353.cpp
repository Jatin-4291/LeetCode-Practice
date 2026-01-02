// Last updated: 1/2/2026, 5:33:53 PM
1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        int n = nums.size() / 2;   // fixed: lenght → size()
5        unordered_map<int,int> mp;
6        int cnt = 0;
7
8        for (int i = 0; i < nums.size(); i++) {
9            if (mp[nums[i]] == 0) cnt++;
10            mp[nums[i]]++;
11        }
12
13        if (cnt == (n + 1)) {
14            for (auto &p : mp) {   // fixed: range-based loop
15                int key = p.first;
16                int val = p.second;
17                if (val == n) {
18                    return key;
19                }
20            }
21        }
22        return -1;
23    }
24};
25