class Solution {
public:
    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        function<int(int, int)> dfs = [&](int r, int c) {
            if (dp[r][c])
                return dp[r][c];

            dp[r][c] = 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    matrix[nr][nc] > matrix[r][c]) {
                    dp[r][c] = max(dp[r][c], 1 + dfs(nr, nc));
                }
            }

            return dp[r][c];
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};
