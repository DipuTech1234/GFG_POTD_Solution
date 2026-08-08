class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        int components = n;
        int extra = 0;

        for (auto &e : edges) {
            int u = find(e[0]);
            int v = find(e[1]);

            if (u == v) {
                extra++;
            } else {
                if (rank[u] < rank[v])
                    swap(u, v);

                parent[v] = u;

                if (rank[u] == rank[v])
                    rank[u]++;

                components--;
            }
        }

        if (extra >= components - 1)
            return components - 1;

        return -1;
    }
};
