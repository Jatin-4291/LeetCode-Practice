// Last updated: 8/30/2025, 1:23:11 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    if(nums[0]+nums[1]> nums[2]){
     if(nums[0]==nums[1] && nums[1]==nums[2] && nums[2]==nums[0]){
        return "equilateral";
     } 
     if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2]){
        return "isosceles";
     }  
     if(nums[0]!=nums[1] || nums[1]!=nums[2] ||nums[2]!=nums[0]){
        return "scalene";
     }
    }
     return "none";
    }
};