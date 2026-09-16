class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int m = n / 2;
        vector<int> second(arr.begin() + m, arr.end());

        sort(second.begin(), second.end());

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int lo = 0, hi = m;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (5LL * second[mid] <= arr[i])
                    lo = mid + 1;
                else
                    hi = mid;
            }

            ans += lo;
        }

        return ans;
    }
};
