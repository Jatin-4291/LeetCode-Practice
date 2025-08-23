// Last updated: 8/23/2025, 2:35:53 PM
class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        if (freq.size() <= k) return 0;

        // Get frequencies of all characters
        vector<int> counts;
        for (auto& [ch, count] : freq) {
            counts.push_back(count);
        }
        sort(counts.begin(), counts.end());

        int to_delete = 0, i = 0;
        while (freq.size() - i > k) {
            to_delete += counts[i];
            i++;
        }

        return to_delete;
    }
};
