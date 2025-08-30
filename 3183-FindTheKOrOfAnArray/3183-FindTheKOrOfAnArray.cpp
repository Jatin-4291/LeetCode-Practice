// Last updated: 8/30/2025, 1:23:25 PM
class Solution {
public:
    // Convert number to binary string without leading zeros
    string convert(int n) {
        if (n == 0) return "0";
        int len = (int)(log2(n));
        return bitset<64>(n).to_string().substr(64 - len - 1);
    }

    int findKOr(vector<int>& nums, int k) {
        vector<string> temp;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            string bin = convert(nums[i]);
            maxLen = max(maxLen, (int)bin.size());
            temp.push_back(bin);
        }

        for (int i = 0; i < temp.size(); i++) {
            while (temp[i].size() < maxLen) {
                temp[i] = '0' + temp[i];
            }
        }
        string ans = "";
        for (int i = 0; i < maxLen; i++) {
            int count = 0;
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j][i] == '1') {
                    count++;
                }
            }
            ans += (count >= k) ? '1' : '0';
        }

        return stoi(ans, nullptr, 2);
    }
};
