// Last updated: 8/30/2025, 1:23:30 PM
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            bool found=false;
            for(int j=0;j<nums.size();j++){
                if(abs(i-j)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                    ans.push_back(i);
                    ans.push_back(j);
                    found=true;
                    break;
                    
                }
            }
                if(found){
                    break;
                }
        }
       return ans.size() > 0 ? ans : vector<int>{-1, -1};

    }
};