class Solution {
public:

    void bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> q;

        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

    int countConnected(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // Because graph is undirected
        }

        // Step 2: Visited array
        vector<int> visited(V, 0);

        // Step 3: Count connected components
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(i, adj, visited);
                components++;
            }
        }

        return components;
    }
};