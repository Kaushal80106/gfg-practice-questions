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
       return topo;
    }
};