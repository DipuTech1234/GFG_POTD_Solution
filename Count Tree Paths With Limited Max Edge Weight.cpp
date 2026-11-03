class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    long long unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return 0;
        }

        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        long long paths = 1LL * sz[u] * sz[v];

        parent[v] = u;
        sz[u] += sz[v];

        return paths;
    }

    vector<int> maximumWeight(int n, vector<vector<int>>& edges,
                              vector<int>& queries) {
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> ans(queries.size(), 0);

        long long totalPaths = 0;
        int edgeIndex = 0;

        for (auto& q : sortedQueries) {
            int limit = q.first;
            int queryIndex = q.second;

            while (edgeIndex < edges.size() &&
                   edges[edgeIndex][2] <= limit) {
                totalPaths += unite(edges[edgeIndex][0],
                                    edges[edgeIndex][1]);

                edgeIndex++;
            }

            ans[queryIndex] = totalPaths;
        }

        return ans;
    }
};
