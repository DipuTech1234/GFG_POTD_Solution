class Solution {
public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();

        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if (j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if (i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 'X')
                    continue;

                int maxLen = min(right[i][j], down[i][j]);

                for (int len = maxLen; len > ans; len--) {
                    int bottom = i + len - 1;
                    int lastCol = j + len - 1;

                    if (right[bottom][j] >= len &&
                        down[i][lastCol] >= len) {
                        ans = len;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
