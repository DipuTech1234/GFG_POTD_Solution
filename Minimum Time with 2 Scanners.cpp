class Solution {
public:
    int minTime(int n, int s1, int s2) {
        long long low = 0, high = 1LL * n * min(s1, s2);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (mid / s1 + mid / s2 >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
