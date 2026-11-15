class Solution {
public:
    int subsequenceSum(string &s) {
        const long long MOD = 1e9 + 7;

        long long sum = 0;
        for (char c : s) {
            sum = (sum + (c - '0')) % MOD;
        }

        long long power = 1;
        long long base = 2;
        long long exp = s.size() - 1;

        while (exp > 0) {
            if (exp & 1)
                power = (power * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (sum * power) % MOD;
    }
};
