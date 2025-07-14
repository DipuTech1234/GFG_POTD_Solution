class Solution {
public:
    int cuts(string s) {
        unordered_set<long long> powersOf5;
        long long power = 1;
        powersOf5.insert(power);
        for (int i = 1; i <= 20; ++i) { // 5^20 is around 1e14, but 2^30 is ~1e9
            power *= 5;
            powersOf5.insert(power);
        }
        
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[j] == '0') {
                    continue; // leading zero is not allowed
                }
                string substring = s.substr(j, i - j);
                long long num = 0;
                for (char c : substring) {
                    num = (num << 1) + (c - '0');
                }
                if (powersOf5.find(num) != powersOf5.end()) {
                    if (dp[j] != INT_MAX) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
