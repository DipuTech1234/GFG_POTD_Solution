class Solution {
public:
    int minimumSum(string &s) {
        int n = s.size();
        int ans = 0;
        char prev = '?';

        for (int i = 0; i < (n + 1) / 2; i++) {
            int j = n - 1 - i;

            if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
                return -1;
            }

            char c = (s[i] != '?') ? s[i] : s[j];

            if (c != '?') {
                if (prev != '?') {
                    ans += 2 * abs(c - prev);
                }
                prev = c;
            }
        }

        return ans;
    }
};
