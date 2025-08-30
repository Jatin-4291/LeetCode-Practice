// Last updated: 8/30/2025, 1:21:25 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[i]<st.top()){
                st.pop();
            }
            if(st.empty() || nums[i]>st.top()){
                if(nums[i]>0) ans++;
                st.push(nums[i]);
            }
        }
        return ans;
    }
};