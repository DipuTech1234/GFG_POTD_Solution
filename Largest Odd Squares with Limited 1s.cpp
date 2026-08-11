class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] =
                    mat[i][j] + pref[i][j + 1] +
                    pref[i + 1][j] - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int x = q[0], y = q[1];

            int lo = 0;
            int hi = min({x, y, n - 1 - x, m - 1 - y});

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                int r1 = x - mid;
                int c1 = y - mid;
                int r2 = x + mid;
                int c2 = y + mid;

                int ones = getSum(r1, c1, r2, c2);

                if (ones <= k)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            ans.push_back(2 * hi + 1);
        }

        return ans;
    }
};
