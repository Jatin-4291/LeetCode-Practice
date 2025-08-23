// Last updated: 8/23/2025, 2:36:01 PM
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> rows;
        long long sum = 0;

        // Row-wise sum
        for (int i = 0; i < n; i++) {
            long long rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += grid[i][j];
                sum += grid[i][j];
            }
            rows.push_back(rowSum);
        }

        // Column-wise sum
        vector<long long> columns;
        for (int j = 0; j < m; j++) {
            long long colSum = 0;
            for (int i = 0; i < n; i++) {
                colSum += grid[i][j];
            }
            columns.push_back(colSum);
        }

        long long temp = 0;
        long long tempSum = sum;
        for (int i = 0; i < columns.size() - 1; i++) {
            temp += columns[i];
            tempSum -= columns[i];
            if (temp == tempSum) {
                return true;
            }
        }
        temp = 0;
        tempSum = sum;
        for (int i = 0; i < rows.size() - 1; i++) {
            temp += rows[i];
            tempSum -= rows[i];
            if (temp == tempSum) {
                return true;
            }
        }

        return false;
    }
};
