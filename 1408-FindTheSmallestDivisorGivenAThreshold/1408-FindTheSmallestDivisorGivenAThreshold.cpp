// Last updated: 8/23/2025, 2:37:12 PM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum += ceil((double)nums[i] / mid);
            }
            if(sum<=threshold){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};