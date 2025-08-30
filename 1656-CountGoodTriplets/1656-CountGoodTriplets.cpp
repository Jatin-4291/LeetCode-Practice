// Last updated: 8/30/2025, 1:25:12 PM
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int first=-1;
        int second=-1;
        int third=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[k]-arr[i])<=c){

                    ans++;
                    }
                }
            }

        }
        return ans;
    }
};