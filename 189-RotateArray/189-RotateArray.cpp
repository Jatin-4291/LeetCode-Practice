// Last updated: 8/23/2025, 2:38:57 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || n <= 1) return;

        int start = 0, count = 0;
        while (count < n) {
            int current = start;
            int a = nums[current];
            
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = a;
                a = temp;
                current = next;
                count++;
            } while (start != current);

            start++;
        }
    }
};
