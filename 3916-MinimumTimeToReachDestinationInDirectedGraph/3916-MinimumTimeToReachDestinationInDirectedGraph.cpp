// Last updated: 8/23/2025, 2:35:35 PM
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adjList(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], s = edge[2], e = edge[3];
            adjList[u].push_back({v, s, e});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        q.push({0, 0}); // {time, node}
        vector<int> visited(n, INT_MAX);

        while (!q.empty()) {
            auto a = q.top();
            q.pop();
            int time = a[0];
            int u = a[1];
            if (visited[u] <= time)
                continue;
            visited[u] = time;

            for (auto& nei : adjList[u]) {
                int v = nei[0], s = nei[1], e = nei[2];

                if (time > e)
                    continue; // time already passed valid window

                int waitTime = max(time, s); // either wait till s or move now
                if (waitTime <= e && waitTime < visited[v]) {
                    q.push({waitTime + 1, v});
                }
            }
        }
        return visited[n - 1] == INT_MAX ? -1 : visited[n - 1];;
    }
};
