// Last updated: 8/30/2025, 1:21:34 PM
class Solution {

    public void dfs(Map<Integer,ArrayList<Integer>> hm, boolean vis[], int i){
        vis[i] = true;
        if(hm.containsKey(i)){            
            ArrayList<Integer> curr = hm.get(i);
            for(int j=0; j<curr.size(); j++){
                
              if(!vis[curr.get(j)])  dfs(hm,vis,curr.get(j));
            }
                
        }
    }
    
    public int numberOfComponents(int[][] properties, int k) {
        Map<Integer,ArrayList<Integer>> hm = new HashMap<>();

        int n = properties.length;
        int m = properties[0].length;

        for(int i=0; i<n; i++){
            HashSet<Integer> hs = new HashSet<>();
            for(int j=0; j<m; j++) hs.add(properties[i][j]);
            
            for(int j=i+1; j<n; j++){
                HashSet<Integer> curr = new HashSet<>();
                for(int l=0; l<m; l++){
                    if(hs.contains(properties[j][l])) {
                        curr.add(properties[j][l]);
                    }    
                }            
                if(curr.size()>=k){
                    hm.computeIfAbsent(i,o->new ArrayList<>()).add(j);
                     hm.computeIfAbsent(j,o->new ArrayList<>()).add(i);
                }
            }
        }

        int tot = 0; 
        boolean vis[] = new boolean[n];

        for(int i=0; i<n; i++){
          if(!vis[i]){
              tot++;
              dfs(hm,vis,i);
          }  
        }

        return tot;
        
    }
}