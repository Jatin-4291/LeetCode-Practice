// Last updated: 8/30/2025, 1:25:46 PM
class Solution {
public:
    bool solveOr(int& i, string& s) {
        bool res = false;
        i += 2; // skip '|' and '('
        while (s[i] != ')') {
            if (s[i] == ',') {
                i++;
                continue;
            }
            res |= solve(i, s);
        }
        i++; // skip ')'
        return res;
    }

    bool solveAnd(int& i, string& s) {
        bool res = true;
        i += 2; // skip '&' and '('
        while (s[i] != ')') {
            if (s[i] == ',') {
                i++;
                continue;
            }
            res &= solve(i, s);
        }
        i++; // skip ')'
        return res;
    }

    bool solve(int& i, string& s) {
        if (s[i] == 't') {
            i++;
            return true;
        }
        if (s[i] == 'f') {
            i++;
            return false;
        }
        if (s[i] == '!') {
            i += 2; // skip '!' and '('
            bool val = !solve(i, s);
            i++; // skip ')'
            return val;
        }
        if (s[i] == '&') {
            return solveAnd(i, s);
        }
        if (s[i] == '|') {
            return solveOr(i, s);
        }
        return false;
    }

    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(i, expression);
    }
};
