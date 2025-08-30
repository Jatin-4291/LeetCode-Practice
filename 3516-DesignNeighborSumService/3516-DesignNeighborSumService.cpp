// Last updated: 8/30/2025, 1:22:26 PM
class NeighborSum {
public:
    vector<vector<int>> grid2;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        grid2 = grid; // Properly assign entire grid
    }
    
    int adjacentSum(int value) {
        int idx = -1, jdx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == value) {
                    idx = i;
                    jdx = j;
                    break;
                }
            }
            if (idx != -1) break;
        }

        if (idx == -1) return 0; // Value not found

        int sum = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [a, b] : directions) {
            int nr = idx + a;
            int nc = jdx + b;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                sum += grid2[nr][nc];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int idx = -1, jdx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == value) {
                    idx = i;
                    jdx = j;
                    break;
                }
            }
            if (idx != -1) break;
        }

        if (idx == -1) return 0; // Value not found

        int sum = 0;
        vector<pair<int, int>> diagonals = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto [a, b] : diagonals) {
            int nr = idx + a;
            int nc = jdx + b;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                sum += grid2[nr][nc];
            }
        }
        return sum;
    }
};
