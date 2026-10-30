class Solution {
public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();

        vector<long long> freq(n + 1, 0);
        for (int x : arr) {
            if (x <= n) freq[x]++;
        }

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        long long product = 1;
        long long prefixCount = 0;

        r = min(r, n);

        for (int mex = 0; mex <= r; mex++) {
            if (mex >= l) {
                long long remaining = n - prefixCount - freq[mex];

                long long ways = (product * pow2[remaining]) % MOD;
                ans = (ans + ways) % MOD;
            }

            product = (product * ((pow2[freq[mex]] - 1 + MOD) % MOD)) % MOD;
            prefixCount += freq[mex];
        }

        return ans;
    }
};
