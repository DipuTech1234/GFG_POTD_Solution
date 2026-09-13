#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partyHouse(vector<vector<int>>& adj) {
        int n = adj.size();

        auto bfs = [&](int src) {
            vector<int> dist(n + 1, -1);
            queue<int> q;

            q.push(src);
            dist[src] = 0;

            int farthest = src;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (dist[u] > dist[farthest])
                    farthest = u;

                for (int v : adj[u - 1]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            return make_pair(farthest, dist);
        };

        // Find one endpoint of the diameter
        auto first = bfs(1);

        // Find the diameter length
        auto second = bfs(first.first);

        int diameter = second.second[second.first];

        // Radius of a tree = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};
