// Last updated: 8/30/2025, 1:23:59 PM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        int n=derived.size();
       for(int i=0;i<n;i++){
        ans^=derived[i];
       } 
       return ans==0?true:false;
    }
};