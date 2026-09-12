class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {
        const long long INF = 4e18;

        vector<long long> mx(k + 1, -INF), mn(k + 1, INF);
        mx[0] = mn[0] = 1;

        for (int x : arr) {
            for (int j = k; j >= 1; --j) {
                if (mx[j - 1] != -INF && mn[j - 1] != INF) {
                    mx[j] = max({mx[j], mx[j - 1] * x, mn[j - 1] * x});
                    mn[j] = min({mn[j], mx[j - 1] * x, mn[j - 1] * x});
                }
            }
        }

        return (int)mx[k];
    }
};
