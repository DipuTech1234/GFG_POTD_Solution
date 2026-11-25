class Solution {
  public:
    int minTime(int a, int b, int d, int l, int r) {
        const long long MOD = 1000000007LL;
        
        long long L = d - r;
        long long R = d - l;
        long long count = R - L + 1;
        
        // Sum of (p + 1) for p from L to R
        long long first = L + 1;
        long long last = R + 1;
        long long linear_sum;
        if (count % 2 == 0) {
            linear_sum = ((count / 2) % MOD) * ((first + last) % MOD) % MOD;
        } else {
            linear_sum = (count % MOD) * (((first + last) / 2) % MOD) % MOD;
        }
        
        // Helper lambda to compute sum_{x=1}^{N} ceil(x / c)
        long long c = a - b;
        auto sum_ceil = [&](long long N) -> long long {
            if (N <= 0) return 0;
            long long q = N / c;
            long long rem = N % c;
            long long full_blocks = (q % MOD) * ((q + 1) % MOD) % MOD;
            full_blocks = full_blocks * ((MOD + 1) / 2) % MOD; // Divide by 2 mod MOD
            full_blocks = full_blocks * c % MOD;
            long long partial_block = (rem % MOD) * ((q + 1) % MOD) % MOD;
            return (full_blocks + partial_block) % MOD;
        };
        
        long long ceil_sum = 0;
        if (R > a) {
            long long start_p = max(L, (long long)a + 1);
            long long upper = R - a;
            long long lower = start_p - a - 1;
            ceil_sum = (sum_ceil(upper) - sum_ceil(lower) + MOD) % MOD;
        }
        
        long long ans = (linear_sum + (2LL * b % MOD) * ceil_sum) % MOD;
        return (int)ans;
    }
};
