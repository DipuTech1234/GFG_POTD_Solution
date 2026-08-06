class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int maxBits = 0;

        for (int x : arr) {
            increments += __builtin_popcount(x);

            int bits = 0;
            while (x > 0) {
                bits++;
                x >>= 1;
            }
            maxBits = max(maxBits, bits);
        }

        return increments + max(0, maxBits - 1);
    }
};
