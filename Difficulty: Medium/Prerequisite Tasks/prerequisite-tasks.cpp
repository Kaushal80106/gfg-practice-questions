class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
         const  int V = N;

        vector<vector<int>> adj(V);

        for(auto i : prerequisites) {
            adj[i.first].push_back(i.second);
        }

      vector<int> indegree(V,0);
        
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
      
       if(topo.size() == V) return true;
        return false ;
    }
};