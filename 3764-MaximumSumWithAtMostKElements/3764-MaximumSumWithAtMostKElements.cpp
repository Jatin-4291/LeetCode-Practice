// Last updated: 8/30/2025, 1:21:46 PM

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        
        // Sort each row in ascending order
        for (int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        priority_queue<int> pq; // Max heap

        // Push top `limits[i]` elements from each row into the priority queue
        for (int i = 0; i < n; i++) {
            int j = 0;
            // cout<<"hello"<< limits[i]<<" "<<(int)grid[i].size()<<endl;
            while (j <limits[i]) { // Ensure within bounds
                // cout<<" helli"<<grid[i].back();
                pq.push(grid[i].back());
                grid[i].pop_back();
                j++;
            }
        }

        // Print all elements inside the priority queue
        // cout << "Priority Queue Elements: ";
        // priority_queue<int> pq_copy = pq;  // Copy pq to avoid modifying the original
        // while (!pq_copy.empty()) {
        //     cout << pq_copy.top() << " ";
        //     pq_copy.pop();
        // }
        cout << endl;

        long long ans = 0;
        int x = 0;

        // Extract the top `k` largest elements from the priority queue
        while (x < k && !pq.empty()) {  // Ensure `pq` isn't empty before popping
            ans += pq.top();
            pq.pop();
            x++;
        }

        return ans;
    }
};
