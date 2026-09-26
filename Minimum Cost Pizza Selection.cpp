class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        int mx = max({s, m, l});
        const int INF = 1e9;

        vector<int> dp(x + mx + 1, INF);
        dp[0] = 0;

        for (int i = 0; i <= x + mx; i++) {
            if (dp[i] == INF) continue;

            if (i + s <= x + mx)
                dp[i + s] = min(dp[i + s], dp[i] + cs);

            if (i + m <= x + mx)
                dp[i + m] = min(dp[i + m], dp[i] + cm);

            if (i + l <= x + mx)
                dp[i + l] = min(dp[i + l], dp[i] + cl);
        }

        int ans = INF;

        for (int i = x; i <= x + mx; i++) {
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};
