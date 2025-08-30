// Last updated: 8/30/2025, 1:22:55 PM
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int countB = 0, countW = 0;
                for (int dx = 0; dx < 2; ++dx) {
                    for (int dy = 0; dy < 2; ++dy) {
                        if (grid[i + dx][j + dy] == 'B') countB++;
                        else countW++;
                    }
                }
                if (countB >= 3 || countW >= 3) return true;
            }
        }
        return false;
    }
};
