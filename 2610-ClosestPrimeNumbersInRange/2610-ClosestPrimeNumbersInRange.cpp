// Last updated: 8/30/2025, 1:24:10 PM

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1};
        vector<int> prime(right + 1, 1);
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= right; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0; 
                }
            }
        }
        vector<int> ans(2, -1);
        int mini = INT_MAX;
        int prev = -1, next = -1;

        for (int i = left; i <= right; i++) {
            if (prime[i] == 1) {
                prev = next;
                next = i;

                if (prev != -1) {
                    int diff = next - prev;
                    if (diff < mini) {
                        mini = diff;
                        ans[0] = prev;
                        ans[1] = next;
                    }
                }
            }
        }

        return ans;
    }
};