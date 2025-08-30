// Last updated: 8/30/2025, 1:24:01 PM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        int x=max(n,m);
        vector<vector<int>> ans; 
        while(i<n && j<m){
            if(nums1[i][0]==nums2[j][0]){
                ans.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
           else if(nums1[i][0]<nums2[j][0]){
            ans.push_back(nums1[i]);
            i++;
           }
           else{
            ans.push_back(nums2[j]);
            j++;
           }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};