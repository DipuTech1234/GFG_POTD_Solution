class Solution {
public:
    int solve(int n, string s) {
        bool seen[26] = {false};
        bool occupied[26] = {false};
        int ans = 0, available = n;

        for (char c : s) {
            int x = c - 'A';

            if (!seen[x]) {
                seen[x] = true;

                if (available > 0) {
                    occupied[x] = true;
                    available--;
                } else {
                    ans++;
                }
            } else {
                if (occupied[x]) {
                    occupied[x] = false;
                    available++;
                }
            }
        }

        return ans;
    }
};
