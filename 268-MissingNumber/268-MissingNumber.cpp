// Last updated: 8/23/2025, 2:38:27 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            int l=0;
            int h=nums.size()-1;
            bool isFound=false;
            while(l<=h){
                int mid=(l+h)/2;
                if(nums[mid]==i){
                    isFound=true;
                    break;
                }
                else if(nums[mid]>i){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(!isFound){
                return i;
            }
        }
        return 0;
    }
};