// Last updated: 8/30/2025, 1:22:29 PM
class Solution {
public:
    int minChanges(int n, int k) {
        // Convert integers to binary strings
        string ns = std::bitset<32>(n).to_string();
        ns.erase(0, ns.find_first_not_of('0'));

        string ks = std::bitset<32>(k).to_string();
        ks.erase(0, ks.find_first_not_of('0'));
        while (ns.length() < ks.length()) ns = '0' + ns;
        while (ks.length() < ns.length()) ks = '0' + ks;

        int count = 0;

        for (int i = 0; i < ns.size(); i++) {
            if (ns[i] != ks[i]) {
                if (ns[i] == '0' && ks[i] == '1') {
                    return -1;
                } else {
                    count++;
                }
            }
        }
        return count;
    }
};
