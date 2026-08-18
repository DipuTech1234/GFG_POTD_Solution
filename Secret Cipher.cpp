#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string compress(string &s) {
        int n = s.length();
        if (n == 0) return "";
        
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        string ans = "";
        int i = n - 1;
        while (i >= 0) {
            if (i % 2 == 1) {
                int half = (i + 1) / 2;
                if (z[half] >= half) {
                    ans += '*';
                    i = half - 1;
                    continue;
                }
            }
            ans += s[i];
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
