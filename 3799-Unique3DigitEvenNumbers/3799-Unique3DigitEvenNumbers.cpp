// Last updated: 8/30/2025, 1:21:36 PM
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solve(int count, vector<int>& digits, int num, unordered_set<int>& uniqueNumbers, vector<bool>& used) {
        if (count == 3) { 
            if (num % 2 == 0) {
                uniqueNumbers.insert(num);
            }
            return;
        }
        
        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue; 
            if (digits[i] == 0 && count == 0) continue; 
            
            used[i] = true;
            solve(count + 1, digits, num * 10 + digits[i], uniqueNumbers, used);
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        vector<bool> used(digits.size(), false); 
        
        solve(0, digits, 0, uniqueNumbers, used);
        
        return uniqueNumbers.size();
    }
};
