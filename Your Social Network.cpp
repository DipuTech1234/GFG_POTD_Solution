class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<vector<int>> ans;

        for (int i = 2; i <= n; i++) {
            vector<int> dist(n + 1, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                int v = arr[u - 2];

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }

            for (int j = 1; j < i; j++) {
                if (dist[j] != -1) {
                    ans.push_back({i, j, dist[j]});
                }
            }
        }

        return ans;
    }
};
