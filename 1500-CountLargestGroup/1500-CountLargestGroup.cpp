// Last updated: 8/30/2025, 1:25:26 PM
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 1; i <= n; i++) {
            int num = i;
            int x = 0;
            
            while (num > 0) {
                x += num % 10;
                num /= 10;
            }
            
            mp[x].push_back(i);
        }

        int ans = 0;
        int maxSize = 0;

        for (auto m : mp) {
            auto [key, val] = m;
            if (val.size() == maxSize) {
                ans++;
            }
            if (val.size() > maxSize) {
                maxSize = val.size();
                ans = 1;
            }
        }

        return ans;
    }
};
