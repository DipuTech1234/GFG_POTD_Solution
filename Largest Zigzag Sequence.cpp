class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> dp = mat[0];

        for (int i = 1; i < n; i++) {
            vector<int> ndp(n, 0);

            int mx1 = -1, mx2 = -1;
            int idx1 = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > mx1) {
                    mx2 = mx1;
                    mx1 = dp[j];
                    idx1 = j;
                } else if (dp[j] > mx2) {
                    mx2 = dp[j];
                }
            }

            for (int j = 0; j < n; j++) {
                int best = (j == idx1 ? mx2 : mx1);
                ndp[j] = mat[i][j] + best;
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
