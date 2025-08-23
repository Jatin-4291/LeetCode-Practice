// Last updated: 8/23/2025, 2:36:08 PM
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> row, col;
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            row[x].insert(y);
            col[y].insert(x);
        }

        int count = 0;
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            auto it = row[x].lower_bound(y);
            bool left = (it != row[x].begin());
            bool right = false;
            if (it != row[x].end()) {
                ++it;
                if (it != row[x].end()) right = true;
            }
            auto it2 = col[y].lower_bound(x);
            bool down = (it2 != col[y].begin());
            bool up = false;
            if (it2 != col[y].end()) {
                ++it2;
                if (it2 != col[y].end()) up = true;
            }

            if (left && right && up && down) {
                count++;
            }
        }

        return count;
    }
};
