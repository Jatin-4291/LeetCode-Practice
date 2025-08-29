// Last updated: 8/29/2025, 4:29:08 PM
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n),suffix(n);
        vector<int> ans(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int k=0;
        int maxi=nums[0];
        for(int i=0;i<n-1;i++){
            maxi=max(nums[i],maxi);
            if(prefix[i]<=suffix[i+1]){
                for(int j=k;j<=i;j++){
                    ans[j]=maxi;
                }
                k=i+1;
                if(k<n) maxi=nums[k];
            }
        }
        maxi=max(maxi,nums[n-1]);
        for(int j=k;j<n;j++){
            ans[j]=maxi;
        }
        return ans;
        
    }
};