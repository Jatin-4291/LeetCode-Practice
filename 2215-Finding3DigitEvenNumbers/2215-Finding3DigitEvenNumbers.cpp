// Last updated: 8/30/2025, 1:24:40 PM
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> first;
        for(int i = 0; i < digits.size(); i++) {
            if(digits[i] != 0) {
                first.push_back(i); // leading digit cannot be zero
            }
        }

        vector<int> second;
        for(int i = 0; i < digits.size(); i++) {
            second.push_back(i); // all indices are valid for second digit
        }

        vector<int> third;
        for(int i = 0; i < digits.size(); i++) {
            if(digits[i] % 2 == 0) {
                third.push_back(i); 
            }
        }

        unordered_set<int> seen;
        vector<int> ans;

        for(int i = 0; i < first.size(); i++) {
            for(int j = 0; j < second.size(); j++) {
                if(first[i] != second[j]) {
                    for(int k = 0; k < third.size(); k++) {
                        if(second[j] != third[k] && first[i] != third[k]) {
                            int num = digits[first[i]] * 100 + digits[second[j]] * 10 + digits[third[k]];
                            if(seen.find(num) == seen.end()) {
                                seen.insert(num);
                                ans.push_back(num);
                            }
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
