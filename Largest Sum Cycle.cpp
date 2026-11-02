
class Solution {
public:
    int largestSumCycle(vector<int>& edge) {
        int n = edge.size();
        vector<int> visited(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            unordered_map<int, int> path;
            int node = i;
            int sum = 0;

            while (node != -1 && !visited[node]) {
                visited[node] = 1;
                path[node] = sum;
                sum += node;
                node = edge[node];
            }

            if (node != -1 && path.count(node)) {
                ans = max(ans, sum - path[node]);
            }
        }

        return ans;
    }
};
