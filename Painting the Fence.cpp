class Solution {
  public:
    int countWays(int n, int k) {
        if (n == 1) return k;

        int same = k;                // for n = 2
        int diff = k * (k - 1);      // for n = 2

        for (int i = 3; i <= n; i++) {
            int new_same = diff;
            int new_diff = (same + diff) * (k - 1);

            same = new_same;
            diff = new_diff;
        }

        return same + diff;
    }
};
