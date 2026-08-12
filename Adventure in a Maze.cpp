class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1000000007;

        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<int>> mx(n, vector<int>(n, -1));

        ways[0][0] = 1;
        mx[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // From top: top cell must allow Down
                if (i > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3)) {
                    ways[i][j] = (ways[i][j] + ways[i - 1][j]) % MOD;

                    if (mx[i - 1][j] != -1) {
                        mx[i][j] = max(mx[i][j],
                                       mx[i - 1][j] + grid[i][j]);
                    }
                }

                // From left: left cell must allow Right
                if (j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 3)) {
                    ways[i][j] = (ways[i][j] + ways[i][j - 1]) % MOD;

                    if (mx[i][j - 1] != -1) {
                        mx[i][j] = max(mx[i][j],
                                       mx[i][j - 1] + grid[i][j]);
                    }
                }
            }
        }

        // If no valid path exists, maximum adventure is 0.
        int maxAdventure = max(0, mx[n - 1][n - 1]);

        return {(int)ways[n - 1][n - 1], maxAdventure};
    }
};
