class Solution {
public:
    int ways(int x, int y) {
        const long long MOD = 1000000007;
        
        long long fact[1001], invFact[1001];
        fact[0] = 1;
        
        for (int i = 1; i <= x + y; i++)
            fact[i] = fact[i - 1] * i % MOD;
        
        auto power = [&](long long a, long long b) {
            long long res = 1;
            while (b) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };
        
        invFact[x + y] = power(fact[x + y], MOD - 2);
        
        for (int i = x + y; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;
        
        return fact[x + y] * invFact[x] % MOD * invFact[y] % MOD;
    }
};
