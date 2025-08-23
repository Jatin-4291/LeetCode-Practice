// Last updated: 8/23/2025, 2:36:47 PM
class Solution {
public:
int findrow(vector<vector<int>>& mat,int r,int mid){
    int index=-1;
    int maxele=INT_MIN;
    for(int i=0;i<r;i++){
        if(mat[i][mid]>maxele){
            maxele=mat[i][mid];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int st=0;
        int end=c-1;
        while(st<=end){
            int mid =st+(end-st)/2;
            int row=findrow(mat,r,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<c? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                end=mid-1;
            }
            else if(mat[row][mid]< right){
                st=mid+1;
            }

        }
        return {-1,-1};
     
        
    }
};