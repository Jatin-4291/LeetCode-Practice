// Last updated: 8/23/2025, 2:35:54 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int startR = -1, startC = -1;
        vector<pair<int,int>> litterPositions;
        unordered_map<int,int> litterId; // map position to id

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }
                if (classroom[i][j] == 'L') {
                    litterId[i*m+j] = litterPositions.size();
                    litterPositions.push_back({i,j});
                }
            }
        }

        if (startR == -1) return -1;
        int totalLitter = litterPositions.size();
        if (totalLitter == 0) return 0;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(n,
            vector<vector<vector<bool>>>(m,
                vector<vector<bool>>(energy+1,
                    vector<bool>(1 << totalLitter, false)
                )
            )
        );

        queue<tuple<int,int,int,int,int>> q;
        q.push({startR, startC, energy, 0, 0});
        visited[startR][startC][energy][0] = true;

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r, c, eLeft, steps, mask] = q.front();
            q.pop();

            if (mask == (1 << totalLitter) - 1) {
                return steps;
            }

            if (eLeft <= 0) continue;

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (classroom[nr][nc] == 'X') continue;

                int newEnergy = eLeft - 1;
                char cell = classroom[nr][nc];
                if (cell == 'R') {
                    newEnergy = energy;
                }

                int newMask = mask;
                if (cell == 'L') {
                    int id = litterId[nr*m + nc];
                    newMask = mask | (1 << id);
                }

                if (!visited[nr][nc][newEnergy][newMask]) {
                    visited[nr][nc][newEnergy][newMask] = true;
                    q.push({nr, nc, newEnergy, steps + 1, newMask});
                }
            }
        }

        return -1;
    }
};
