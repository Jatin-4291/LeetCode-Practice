// Last updated: 8/30/2025, 1:21:24 PM
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == '#' || matrix[m - 1][n - 1] == '#')
            return -1;

        unordered_map<char, vector<pair<int, int>>> portals;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = matrix[i][j];
                if (isupper(ch)) {
                    portals[ch].push_back({i, j});
                }
            }
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        unordered_set<char> usedPortals;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!pq.empty()) {
            auto [moves, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1)
                return moves;

            if (dist[i][j] < moves)
                continue;
            
            if (isupper(matrix[i][j])) {
                char portal = matrix[i][j];
                if (usedPortals.find(portal) == usedPortals.end()) {
                    usedPortals.insert(portal);
                    for (auto &[pi, pj] : portals[portal]) {
                        if (dist[pi][pj] > moves) {
                            dist[pi][pj] = moves;
                            pq.push({moves, pi, pj});
                        }
                    }
                }
            }

            for (auto [dx, dy] : directions) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[ni][nj] != '#') {
                    if (dist[ni][nj] > moves + 1) {
                        dist[ni][nj] = moves + 1;
                        pq.push({moves + 1, ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};
