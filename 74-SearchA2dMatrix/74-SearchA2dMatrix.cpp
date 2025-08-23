// Last updated: 8/23/2025, 2:39:55 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int h=matrix.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(matrix[mid][0]<=target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<h;
        if(h==-1){
            return false;
        }
        int row=h;
        l=0;
        h=matrix[0].size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<=target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};