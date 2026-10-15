class Solution {
  public:
    int maxValue(int n) {
        while (n & (n >> 1) & (n >> 2)) {
            int i = 31;
            while (i >= 2) {
                if ((n & (1 << i)) &&
                    (n & (1 << (i - 1))) &&
                    (n & (1 << (i - 2)))) {
                    n &= ~(1 << (i - 2));
                    break;
                }
                i--;
            }
        }
        return n;
    }
};
