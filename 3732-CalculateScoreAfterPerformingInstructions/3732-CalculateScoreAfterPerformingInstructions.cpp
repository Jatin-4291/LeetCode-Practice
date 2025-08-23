// Last updated: 8/23/2025, 2:36:19 PM
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        vector<bool> visited(n, false);
        int i = 0;
        long long ans = 0;

        while (i >= 0 && i < n && !visited[i]) {
            visited[i] = true;

            if (instructions[i] == "jump") {
                int jump = values[i];
                i = i + jump;
                if (i < 0 || i >= n) break;

            } else if (instructions[i] == "add") {
                ans += values[i];
                i++;
            }
        }

        return ans;
    }
};
