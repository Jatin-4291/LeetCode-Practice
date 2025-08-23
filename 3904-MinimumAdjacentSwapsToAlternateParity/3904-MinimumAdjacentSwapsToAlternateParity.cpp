// Last updated: 8/23/2025, 2:35:43 PM
class Solution {
public:
    int solve(vector<int>& x, int a) {
        int moves = 0;
        for (int i = 0; i < x.size(); ++i) {
            moves += abs(x[i] - (a + 2 * i));
        }
        return moves;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }

        int evenCount = even.size(), oddCount = odd.size();
        if (abs(evenCount - oddCount) > 1)
            return -1;

        if (evenCount == oddCount) {
            return min(solve(even, 0), solve(odd, 0));
        } else if (evenCount > oddCount) {
            return solve(even, 0);
        } else {
            return solve(odd, 0);
        }
    }
};
