// Last updated: 9/21/2025, 8:47:26 PM
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        set<vector<int>> visited;
        queue<pair< vector<int>, int >> Q;

        Q.push({nums1, 0});
        visited.insert(nums1);

        while(!Q.empty()){

            auto [currentConfig, count] = Q.front();
            Q.pop();

            if(currentConfig == nums2) return count;

            for( int s = 0; s < n; s++ ){
                for( int e = s; e < n; e++){

                    vector<int> splitPart;
                    for( int i = s; i <= e; i++) splitPart.push_back(currentConfig[i]);

                    vector<int> remainingPart;
                    for( int i = 0; i < s; i++) remainingPart.push_back(currentConfig[i]);
                    for( int i = e+1; i < n; i++) remainingPart.push_back(currentConfig[i]);

                    for( int i = 0; i <= remainingPart.size(); i++){

                        vector<int> nextConfig;

                        for( int j = 0; j < i; j++) 
                            nextConfig.push_back(remainingPart[j]);
                        for( int j = 0; j < splitPart.size(); j++) 
                            nextConfig.push_back(splitPart[j]);
                        for( int j = i; j < remainingPart.size(); j++)
                            nextConfig.push_back(remainingPart[j]);

                        if(!visited.count(nextConfig)){
                            Q.push({ nextConfig, count+1 });
                            visited.insert(nextConfig);
                        } 

                    }

                                        
                }
            }

        }


        return -1;          
    }
};