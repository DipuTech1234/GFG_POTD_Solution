class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total = 0;

        for (int len = 1; len <= n; len++) {
            int m = len / 2;
            int middle = len % 2;

            if (m > k) continue;

            long long ways = 1;
            for (int i = 0; i < m; i++) {
                ways = (ways * (k - i)) % MOD;
            }

            if (middle == 1) {
                long long rem_chars = k - m;
                if (rem_chars <= 0) continue;
                ways = (ways * rem_chars) % MOD;
            }

            total = (total + ways) % MOD;
        }

        return total;
    }
};
