// Last updated: 8/30/2025, 1:22:21 PM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        long long r = LLONG_MIN; // Long long to avoid overflow
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            vector<vector<int>> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back({board[i][j], i, j});
            }
            
            sort(temp.begin(), temp.end(), [](vector<int>& a, vector<int>& b) {
                return a[0] > b[0];
            });
            
            result.push_back(temp[0]);
            if (n > 1) result.push_back(temp[1]);
            if (n > 2) result.push_back(temp[2]);
        }
        
        for(int i = 0; i < result.size(); i++) {
            int f1 = result[i][0];
            int f2 = result[i][1];
            int f3 = result[i][2];
            
            for(int j = i+1; j < result.size(); j++) {
                int s1 = result[j][0];
                int s2 = result[j][1];
                int s3 = result[j][2];
                
                for(int k = j+1; k < result.size(); k++) {
                    int t1 = result[k][0];
                    int t2 = result[k][1];
                    int t3 = result[k][2];
                    
                    if(f2 != s2 && s2 != t2 && f2!=t2 && f3 != s3 && f3!=t3 && s3 != t3) {
                        long long sum = (long long)f1 + s1 + t1; // Use long long to store the sum
                        r = max(r, sum);
                    }
                }
            }
        }
        
        return r;
    }
};