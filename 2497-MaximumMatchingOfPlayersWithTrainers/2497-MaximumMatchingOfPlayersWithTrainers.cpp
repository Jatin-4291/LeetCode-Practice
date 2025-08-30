// Last updated: 8/30/2025, 1:24:20 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0;
        int j=0;
        while(i<players.size()&&j<trainers.size()){
            if(trainers[j]>=players[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};