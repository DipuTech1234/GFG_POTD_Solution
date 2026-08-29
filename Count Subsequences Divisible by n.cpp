class Solution {
public:
    int countSubsequences(string s, int n) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n, 0);

        for (char ch : s) {
            int d = ch - '0';
            vector<long long> cur = dp;

            // Start a new subsequence with this digit
            cur[d % n] = (cur[d % n] + 1) % MOD;

            // Append this digit to every existing subsequence
            for (int r = 0; r < n; ++r) {
                if (dp[r] == 0) continue;

                int nr = ((long long)r * 10 + d) % n;
                cur[nr] = (cur[nr] + dp[r]) % MOD;
            }

            dp.swap(cur);
        }

        return dp[0];
    }
};
