// Last updated: 8/30/2025, 1:25:40 PM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0; 
            }
        }
        return false;
    }
};
