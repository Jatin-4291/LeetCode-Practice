// Last updated: 8/30/2025, 1:24:51 PM
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> prev(m, 0), curr(m, 0);

        // Initialize first row
        for (int j = 0; j < m; j++) {
            prev[j] = points[0][j];
        }

        // Iterate over rows
        for (int i = 1; i < n; i++) {
            vector<long long> left(m, 0), right(m, 0);

            // Left to right pass
            left[0] = prev[0];  
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, prev[j]);  
            }
            right[m - 1] = prev[m - 1];  
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prev[j]);  
            }

            // Compute current row values
            for (int j = 0; j < m; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);  
            }

            prev = curr;  // Move to next row
        }

        return *max_element(prev.begin(), prev.end());
    }
};
