// Last updated: 9/1/2025, 3:58:35 PM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans(friends.size(),-1);
        int k=0;
       for(int i=0;i<order.size();i++){
            int key=order[i];
            int l=0;
            int h=friends.size()-1;
            while(l<=h){
                int mid=(l+h)/2;
                if(friends[mid]==key){
                    ans[k++]=key;
                    break;
                }else if(friends[mid]<key){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
       }
       return ans; 
    }
};