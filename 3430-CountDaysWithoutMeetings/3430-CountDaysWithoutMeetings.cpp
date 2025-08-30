// Last updated: 8/30/2025, 1:22:49 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings based on start day
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // Merging overlapping intervals
        vector<vector<int>> merged;
        for (auto& meeting : meetings) {
            if (merged.empty() || merged.back()[1] < meeting[0] - 1) {
                // No overlap, add new interval
                merged.push_back(meeting);
            } else {
                // Overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], meeting[1]);
            }
        }

        int ans = 0;

        // Count free days
        for (int i = 0; i < merged.size(); i++) {
            if (i == 0) { 
                if (merged[i][0] - 1 > 0) {
                    ans += merged[i][0] - 1;
                }
            } else {
                if (merged[i][0] - merged[i-1][1] - 1 > 0) {
                    ans += merged[i][0] - merged[i-1][1] - 1;
                }
            }
        }

        if (days - merged.back()[1] > 0) {
            ans += days - merged.back()[1];
        }

        return ans;
    }
};
