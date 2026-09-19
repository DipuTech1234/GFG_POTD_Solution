class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size(), m = s2.size();
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - 1] + costS1 + costS2);
                }
            }
        }
        
        long long totalCost = 1LL * n * costS1 + 1LL * m * costS2;
        return totalCost - dp[n][m];
    }
};
