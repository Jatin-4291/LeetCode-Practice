// Last updated: 8/30/2025, 1:22:05 PM
class Solution {
public:
    bool isDistint(unordered_map<int,int>& mp){
        for(auto m : mp){
            if(m.second > 1){
                return false;
            }
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = 0;
        for(int i = 0; i < n; i += 3){
            if(isDistint(mp)){
                return ans;
            }
            for(int j = i; j < i + 3 && j < n; j++){
                mp[nums[j]]--;
            }

            
            ans++;
        }
        return ans;
    }
};
