class Solution {
public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &d : dependencies) {
            int u = d[0], v = d[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        vector<long long> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = duration[i];
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        long long ans = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            ans = max(ans, dp[u]);

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + duration[v]);

                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return (count == n) ? (int)ans : -1;
    }
};
