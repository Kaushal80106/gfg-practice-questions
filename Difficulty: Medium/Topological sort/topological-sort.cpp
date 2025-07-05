class Solution {
    
    private: 
    void dfs(int node , int  vis[] , vector<vector<int>>& adj , stack<int> &st) 
    {
        vis[node] = 1 ;
        
        for(auto i : adj[node]) {
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        
        int vis[V] = {0};
        
        stack<int> st;
        for( int i = 0;i<V;i++){
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }
        vector<int> ans ;
        
        while(!st.empty()) {
            ans.push_back(st.top()) ;
            st.pop();
        }
        
        return ans ;
    }
};