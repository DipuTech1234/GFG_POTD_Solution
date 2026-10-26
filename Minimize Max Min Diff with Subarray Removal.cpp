class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();

        vector<int> prefMin(n), prefMax(n);
        vector<int> suffMin(n), suffMax(n);

        prefMin[0] = prefMax[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefMin[i] = min(prefMin[i - 1], arr[i]);
            prefMax[i] = max(prefMax[i - 1], arr[i]);
        }

        suffMin[n - 1] = suffMax[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], arr[i]);
            suffMax[i] = max(suffMax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n - k; i++) {
            int mn = INT_MAX;
            int mx = INT_MIN;

            if (i > 0) {
                mn = min(mn, prefMin[i - 1]);
                mx = max(mx, prefMax[i - 1]);
            }

            if (i + k < n) {
                mn = min(mn, suffMin[i + k]);
                mx = max(mx, suffMax[i + k]);
            }

            if (mn == INT_MAX) return 0;

            ans = min(ans, mx - mn);
        }

        return ans;
    }
};
