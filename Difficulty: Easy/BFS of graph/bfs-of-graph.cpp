class Solution {
  public:
  
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> visited(V,0);
        vector<int> res;
        queue<int> q;
        
        q.push(0);
        visited[0]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }
        return res;
    }
};


