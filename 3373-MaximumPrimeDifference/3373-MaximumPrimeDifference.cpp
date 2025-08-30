// Last updated: 8/30/2025, 1:23:02 PM
class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int firstIndex = -1, lastIndex = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                if (firstIndex == -1) firstIndex = i;
                lastIndex = i;
            }
        }
        
        return (firstIndex == -1) ? 0 : (lastIndex - firstIndex);
    }
};
