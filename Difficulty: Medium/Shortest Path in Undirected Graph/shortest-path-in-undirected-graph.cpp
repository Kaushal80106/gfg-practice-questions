class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int N = adj.size();
        int dist[N] ;
        
        for(int i = 0; i<N;i++) {
            dist[i] = INT_MAX ;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src) ;
        
        while(!q.empty()) {
            int node = q.front() ;
            q.pop();
          for(auto it : adj[node]) {
              if(dist[node] + 1 < dist[it]) {
                  dist[it] = dist[node]+1;
                  q.push(it);
              }
            
          }    
        }
        
        vector<int> ans(N,-1) ;
        
        for(int i = 0 ;i<N;i++) {
            if(dist[i] != INT_MAX) {
                ans[i] = dist[i];
            }
        }
        
        return ans ;
    }
};