// Last updated: 9/11/2025, 11:00:18 PM
class Solution {
public:

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        int m=languages.size();
        int res=INT_MAX;
        vector<vector<int>> all(m,vector<int>(n,0));

        // make a adjacency matrix of mambers and languages known by them
        for(int i=0;i<m;i++){
            for(int x:languages[i])
                all[i][x-1]=1;
        }

        // for the ones that cant communicate, store their  in teach array 
        vector<int> teach(m,0);
        for(auto x:friendships){
            int f=0;
            for(int i=0;i<n;i++){
                if(all[x[0]-1][i]==1 && all[x[1]-1][i]==1){
                    f=1;
                    break;
                }
            }
            if(f==0){
                teach[x[0]-1]=1;
                teach[x[1]-1]=1;
            }

        }

        // go through each language and check if needs to be taught to that person
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(teach[j]==1 && all[j][i]==0)
                    c++;
            }
            res=min(res,c);
        }

        return res;
        
    }
};