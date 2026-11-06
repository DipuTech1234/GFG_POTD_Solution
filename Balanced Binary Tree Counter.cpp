class Solution {
public:
    int countBT(int h) {
        const long long MOD = 1000000007;

        if (h == 0 || h == 1)
            return 1;

        long long prev2 = 1;
        long long prev1 = 1;

        for (int i = 2; i <= h; i++) {
            long long curr = (prev1 * prev1 +
                              2 * prev1 * prev2) % MOD;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
