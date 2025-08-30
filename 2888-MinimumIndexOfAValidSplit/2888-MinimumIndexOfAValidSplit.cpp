// Last updated: 8/30/2025, 1:23:46 PM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      unordered_map<int,int> mp;
      int n=nums.size();
      for(int i=0;i<n;i++){
        mp[nums[i]]++;
      }  
      int dominant=0;
      int temp=0;
      for(auto&m:mp){
        if(m.second>temp){
            temp=m.second;
            dominant=m.first;
        }
      }
      int countDominant=0;
      int ans=-1;
      for(int i=0;i<n;i++){
        if(nums[i]==dominant){
            countDominant++;
        }
        if(countDominant*2>(i+1) && (mp[dominant]-countDominant)*2>(n-(i+1)))
        {
            ans=i;
            break;
        }
      }
      return ans;

    }
};