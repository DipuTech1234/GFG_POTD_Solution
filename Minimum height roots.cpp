class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;

        // Push all leaf nodes
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remaining = V;

        // Trim leaves layer by layer
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
