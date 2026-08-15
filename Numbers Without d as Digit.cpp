class Solution {
public:
    long long countWithout(int n, int d) {
        string s = to_string(n);
        long long dp[11][2][2][2];
        memset(dp, 0, sizeof(dp));
        
        dp[0][1][0][0] = 1;
        
        for (int pos = 0; pos < (int)s.size(); pos++) {
            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {
                    for (int found = 0; found <= 1; found++) {
                        long long ways = dp[pos][tight][started][found];
                        if (!ways) continue;
                        
                        int limit = tight ? s[pos] - '0' : 9;
                        
                        for (int dig = 0; dig <= limit; dig++) {
                            int ntight = tight && (dig == limit);
                            int nstarted = started || (dig != 0);
                            int nfound = found;
                            
                            if (nstarted && dig == d)
                                nfound = 1;
                            
                            dp[pos + 1][ntight][nstarted][nfound] += ways;
                        }
                    }
                }
            }
        }
        
        long long without = 0;
        for (int tight = 0; tight <= 1; tight++) {
            for (int started = 0; started <= 1; started++) {
                without += dp[s.size()][tight][started][0];
            }
        }
        
        // Exclude 0, since we need numbers from 1 to n.
        return without - 1;
    }
};
