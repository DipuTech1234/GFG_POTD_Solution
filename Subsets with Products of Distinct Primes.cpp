class Solution {
public:
    int countSubsets(vector<int> &arr) {
        const int MOD = 1000000007;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> valMask(31, -1);
        valMask[1] = 0;

        for (int v = 2; v <= 30; v++) {
            int x = v, mask = 0;
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                int cnt = 0;
                while (x % primes[i] == 0) {
                    x /= primes[i];
                    cnt++;
                }
                if (cnt > 1) {
                    ok = false;
                    break;
                }
                if (cnt == 1) mask |= (1 << i);
            }
            if (ok && x == 1) valMask[v] = mask;
        }

        int ones = 0;
        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int x : arr) {
            if (x == 1) {
                ones++;
                continue;
            }
            int m = valMask[x];
            if (m == -1) continue;

            for (int mask = (1 << 10) - 1; mask >= 0; mask--) {
                if ((mask & m) == 0) {
                    dp[mask | m] = (dp[mask | m] + dp[mask]) % MOD;
                }
            }
        }

        long long mul = 1;
        while (ones--) mul = (mul * 2) % MOD;

        long long ans = 0;
        for (int mask = 1; mask < (1 << 10); mask++) {
            ans = (ans + dp[mask]) % MOD;
        }

        ans = (ans * mul) % MOD;
        return (int)ans;
    }
};
