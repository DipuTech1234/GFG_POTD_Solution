class Solution {
public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> edges) {
        vector<vector<pair<int, int>>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        const int NEG_INF = INT_MIN;
        vector<int> dist(V, NEG_INF);
        dist[src] = 0;

        for (int u : topo) {
            if (dist[u] == NEG_INF)
                continue;

            for (auto &[v, w] : adj[u]) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};
