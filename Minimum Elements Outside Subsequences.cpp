class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[i][j] = maximum elements selected when the last
        // element of increasing subsequence is i and decreasing is j.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        dp[0][0] = 0;

        for (int k = 1; k <= n; k++) {
            int x = arr[k - 1];

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (dp[i][j] == -1) continue;

                    // Leave arr[k-1] unused
                    dp[i][j] = max(dp[i][j], dp[i][j]);

                    // Put arr[k-1] in increasing subsequence
                    if (i == 0 || arr[i - 1] < x) {
                        dp[k][j] = max(dp[k][j], dp[i][j] + 1);
                    }

                    // Put arr[k-1] in decreasing subsequence
                    if (j == 0 || arr[j - 1] > x) {
                        dp[i][k] = max(dp[i][k], dp[i][j] + 1);
                    }
                }
            }
        }

        int maximum = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maximum = max(maximum, dp[i][j]);
            }
        }

        return n - maximum;
    }
};
