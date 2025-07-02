class Solution {
    
    private :
    
    bool dfs(int node ,vector<vector<int>> adj ,int vis[] ,int pathVis[]) {
        
        vis[node] = 1;
        pathVis[node] = 1 ;
        
        for(auto i : adj[node]) {
            
          if(!vis[i]) {
                if(dfs(i,adj,vis,pathVis) == true) return true;
          }
              else if(pathVis[i] == true) return true;
        }
        pathVis[node] = 0 ;
        return false ;
      
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V) ;
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0} ;
        
        for(int i = 0;i<V;i++) {
            
            if(!vis[i]) {
                if(dfs(i,adj,vis,pathVis) == true) return true ;
            }
        }
        return false ;
    }
};