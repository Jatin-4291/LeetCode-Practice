// Last updated: 8/30/2025, 1:23:43 PM
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            
            if(s.size() % 2 == 1) continue; 
            
            int m = 0, n = s.size() - 1;
            int left = 0, right = 0;
            
            while(m < n){
                left += s[m] - '0';
                right += s[n] - '0';
                m++;
                n--;
            }
            
            if(left == right){
                ans++;
            }
        }
        return ans;
    }
};
