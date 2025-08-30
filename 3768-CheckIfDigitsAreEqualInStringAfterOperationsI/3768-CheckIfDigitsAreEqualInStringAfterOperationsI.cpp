// Last updated: 8/30/2025, 1:21:45 PM
#include <queue>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        queue<int> q;

        // Convert string characters to digits and store them in the queue
        for (char c : s) {
            q.push(c - '0');
        }

        // Process until only 2 digits remain
        while (q.size() > 2) {
            int size = q.size(); // Store the initial queue size
            
            for (int i = 0; i < size - 1; i++) {
                int x = q.front(); 
                q.pop();
                int sum = (x + q.front()) % 10; // Get new digit
                q.push(sum);
            }

            q.pop(); // Remove last element to reduce the queue size properly
        }
        int first = q.front(); q.pop();
        int second = q.front();

        return first == second;
    }
};
