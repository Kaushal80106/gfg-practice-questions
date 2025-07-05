class Solution {
    
    // private :
    
    // bool dfs(int node ,vector<vector<int>> adj ,int vis[] ,int pathVis[]) {
        
    //     vis[node] = 1;
    //     pathVis[node] = 1 ;
        
    //     for(auto i : adj[node]) {
            
    //       if(!vis[i]) {
    //             if(dfs(i,adj,vis,pathVis) == true) return true;
    //       }
    //           else if(pathVis[i] == true) return true;
    //     }
    //     pathVis[node] = 0 ;
    //     return false ;
      
    // }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
      vector<vector<int>> adj(V);
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        
        int indegree[V] = {0};
        
       for(int i = 0 ;i<V;i++) {
           for(auto it : adj[i]) 
           {
               indegree[it]++;
           }
       }
       
       queue<int> q;
       
       for(int i = 0 ; i < V ;i++) {
           if(indegree[i] == 0) {
               q.push(i);
           }
       }
        vector<int> topo ;
       while(!q.empty()) {
           int node = q.front();
           q.pop();
           topo.push_back(node);
           
           for(auto it : adj[node]) {
               indegree[it]--;
               if(indegree[it] == 0) {
                   q.push(it);
               }
           }
       }
       if (topo.size() < V) return true;
       unordered_map<int,int> mp ;
       
       for(int i = 0 ;i< V;i++) {
           mp[topo[i]] = i ;
       }
       
       
      for(auto i : edges) {
          if(mp[i[0]] > mp[i[1]]) return true ;
      }
       return false;
    }
};