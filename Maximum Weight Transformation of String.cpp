class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            int gain = (s[i - 1] != s[i - 2]) ? 2 : 1;
            dp[i] = max(dp[i - 1], dp[i - 2] + gain);
        }

        return n + dp[n];
    }
};
