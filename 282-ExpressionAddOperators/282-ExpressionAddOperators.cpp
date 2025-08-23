// Last updated: 8/23/2025, 2:38:26 PM
class Solution {
public:
    void solve(int i, string& num, long long curr, long long prev, int target, string temp, vector<string>& ans) {
        if (i == num.size()) {
            if (curr == target) {
                ans.push_back(temp);
            }
            return;
        }

        string next = "";
        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') break;  // prevent numbers with leading zeros

            next += num[j];
            long long val = stoll(next);

            // +
            solve(j + 1, num, curr + val, val, target, temp + "+" + next, ans);

            // -
            solve(j + 1, num, curr - val, -val, target, temp + "-" + next, ans);

            // *
            solve(j + 1, num, curr - prev + prev * val, prev * val, target, temp + "*" + next, ans);
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string first = "";

        for (int i = 0; i < num.size(); i++) {
            first += num[i];
            if (i > 0 && num[0] == '0') break;  // leading 0 check

            long long val = stoll(first);
            solve(i + 1, num, val, val, target, first, ans);
        }

        return ans;
    }
};
