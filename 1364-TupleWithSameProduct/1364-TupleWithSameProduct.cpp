// Last updated: 8/30/2025, 1:25:37 PM
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        
        // Store all pairs with their product
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto& p : mp) {
            int size = p.second;
            if (size > 1) {
                count += ((size * (size - 1)) / 2 )* 8; 
            }
        }
        
        return count;
    }
};
