// Last updated: 8/30/2025, 1:24:35 PM
class Solution { 
public: 
    int numberOfArrays(vector<int>& differences, int lower, int upper) { 
        int n = differences.size(); 
        vector<long long> prefix(n);
        prefix[0] = differences[0];

        for (int i = 1; i < n; i++) { 
            prefix[i] = prefix[i - 1] + differences[i]; 
        } 

        long long mini = 0, maxi = 0; 
        for (int i = 0; i < n; i++) { 
            mini = min(mini, prefix[i]); 
            maxi = max(maxi, prefix[i]); 
        } 

        long long minStart = (long long)lower - mini; 
        long long maxStart = (long long)upper - maxi; 

        return max(0LL, maxStart - minStart + 1); 
    } 
};
