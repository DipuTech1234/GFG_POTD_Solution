#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPath(string s, vector<vector<int>>& edges) {
        int n = s.size();

        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n, -1), order;
        parent[0] = -2;
        order.push_back(0);

        for (int i = 0; i < n; i++) {
            int u = order[i];

            for (int v : g[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        // down[u] = longest same-colored path starting at u
        // and going into its subtree.
        vector<int> down(n, 1);

        int ans = 1;

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            int best1 = 0, best2 = 0;

            for (int v : g[u]) {
                if (parent[v] != u)
                    continue;

                if (s[v] == s[u]) {
                    int x = down[v];

                    if (x > best1) {
                        best2 = best1;
                        best1 = x;
                    } else if (x > best2) {
                        best2 = x;
                    }
                }
            }

            down[u] = 1 + best1;

            // Same-colored path passing through u
            ans = max(ans, 1 + best1 + best2);
        }

        // up[u] = longest same-colored path starting at u
        // and going through its parent side.
        vector<int> up(n, 1);

        for (int u : order) {
            int best1 = 0, best2 = 0;
            int bestChild = -1;

            for (int v : g[u]) {
                if (parent[v] != u)
                    continue;

                if (s[v] != s[u])
                    continue;

                int x = down[v];

                if (x > best1) {
                    best2 = best1;
                    best1 = x;
                    bestChild = v;
                } else if (x > best2) {
                    best2 = x;
                }
            }

            for (int v : g[u]) {
                if (parent[v] != u)
                    continue;

                if (s[v] != s[u]) {
                    up[v] = 1;
                    continue;
                }

                int best = up[u];

                // Go from u into another child.
                if (bestChild != v)
                    best = max(best, best1 + 1);
                else
                    best = max(best, best2 + 1);

                up[v] = best + 1;
            }
        }

        // A valid path can have:
        // same color ... same color -> different color ... different color
        //
        // Check every edge where the colors differ.
        for (int v = 1; v < n; v++) {
            int u = parent[v];

            if (s[u] == s[v])
                continue;

            int left = max(down[u], up[u]);
            int right = max(down[v], up[v]);

            ans = max(ans, left + right);
        }

        return ans;
    }
};
