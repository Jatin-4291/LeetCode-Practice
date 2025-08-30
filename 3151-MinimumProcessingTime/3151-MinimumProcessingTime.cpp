// Last updated: 8/30/2025, 1:23:33 PM
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int ans=0;
        int j=0;
        for(int i=0;i<processorTime.size();i++){
            ans=max(ans,processorTime[i]+tasks[j]);
            j+=4;
        }
        return ans;
    }
};