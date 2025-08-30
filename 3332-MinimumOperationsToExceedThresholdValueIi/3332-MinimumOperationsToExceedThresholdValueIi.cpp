// Last updated: 8/30/2025, 1:23:09 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq; // Use long long

        for (int num : nums) {
            pq.push(num);
        }

        int operations = 0;

        while (pq.size() > 1 && pq.top() < k) {
            operations++;
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            long long num = (2 * x) + y; 
            pq.push(num);
        }

        return operations;
    }
};
