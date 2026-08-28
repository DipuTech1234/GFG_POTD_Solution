class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<int> dp(3);
        for (int j = 0; j < 3; j++)
            dp[j] = mat[0][j];
        
        for (int i = 1; i < n; i++) {
            vector<int> ndp(3);
            
            for (int j = 0; j < 3; j++) {
                ndp[j] = mat[i][j] + min(dp[(j + 1) % 3],
                                         dp[(j + 2) % 3]);
            }
            
            dp = ndp;
        }
        
        return min({dp[0], dp[1], dp[2]});
    }
};
