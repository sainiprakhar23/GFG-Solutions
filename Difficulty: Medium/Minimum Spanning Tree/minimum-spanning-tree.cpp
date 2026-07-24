class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<pair<int,int>> adj[V];

        // Creating adjacency list
        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];      
            int edgeweight = edges[i][2];

            adj[src].push_back({dest, edgeweight});
            adj[dest].push_back({src, edgeweight});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0,0});

        vector<int> visited(V,0);

        int ans = 0;

        while(!pq.empty()) {

            pair<int,int> p = pq.top();
            pq.pop();

            int cost = p.first;
            int node = p.second;

            if(visited[node])
                continue;

            visited[node] = 1;
            ans += cost;

            for(pair<int,int> it : adj[node]) {

                int neighbour = it.first;
                int weight = it.second;

                if(!visited[neighbour]) {
                    pq.push({weight, neighbour});
                }
            }
        }

        return ans;
    }
};