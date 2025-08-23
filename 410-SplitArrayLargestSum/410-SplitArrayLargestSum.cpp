// Last updated: 8/23/2025, 2:38:10 PM
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        cout<<l<<" "<<h<<" ";
        while(l<=h){
            int mid=(l+h)/2;
            cout<<"mid"<<mid;
            int sum=0;
            int count=1;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    count++;
                    sum=nums[i];
                }else{
                    sum+=nums[i];
                }
            }
            cout<<"count"<<count<<endl;
            if(count>k){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return l;
    }
};