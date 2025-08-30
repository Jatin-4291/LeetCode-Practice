// Last updated: 8/30/2025, 1:22:40 PM
class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string turn, int vowelCount) {
        string key = turn + "_" + to_string(vowelCount);
        if (memo.count(key)) return memo[key];

        if (vowelCount == 0) return false; // no move possible, current player loses

        int move = 0;
        if (turn == "alice") {
            if (vowelCount % 2 == 1) move = vowelCount;       // max odd
            else if (vowelCount > 1) move = vowelCount - 1;   // next lower odd
        } else {
            if (vowelCount % 2 == 0) move = vowelCount;       // max even
            else move = vowelCount - 1;                       // next lower even
        }
        if (move <= 0) return memo[key] = false;
        bool opponentWins = solve(turn == "alice" ? "bob" : "alice", vowelCount - move);
        return memo[key] = !opponentWins;
    }

    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for (char c : s) {
            if (isVowel(c)) vowelCount++;
        }
        return solve("alice", vowelCount);
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
