// Last updated: 8/23/2025, 2:38:07 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(),intervals.end());
        st.push(intervals[0]);
        int removal=0;
        for(int i=1;i<intervals.size();i++){
            if(st.top()[1]>intervals[i][0]){
               removal++;
               if (intervals[i][1] < st.top()[1]) {
                    st.pop();
                    st.push(intervals[i]);
                }
            }
            else{
               st.push(intervals[i]); 
            }
        }
        return removal;
    }
};