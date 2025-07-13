// User function Template for C++
class Solution {
    
    private :
    void topoSort(int node , int vis[] , vector<pair<int,int>> adj[] , stack<int> &st) {
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            int v = it.first ;
            
            if(!vis[v]) {
                topoSort(v,vis ,adj,st);
            }
        }
        
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int N, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[N] ;
        
        for(int i = 0 ; i < E ;i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt}) ;
            
        } 
        
         stack<int> st ;
            int vis[N] = {0} ;
            
            
            for(int i = 0;i<N;i++){
                
                if(!vis[i]) {
                   topoSort(i , vis ,adj,st); 
                }
             }
             
             vector<int> dis(N) ;
             
             for(int i = 0 ;i<N;i++) 
                dis[i] = INT_MAX;
             
              dis[0] = 0 ;
              
             while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dis[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dis[node] + wt < dis[v]) {
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }
              
              
              for(int i = 0 ;i<N;i++) {
                  if(dis[i] == INT_MAX) dis[i] = -1;
              }
              return dis ;
    }
};
