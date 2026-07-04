class Solution {
public:
    int countSubstring(string s) {
        int n = s.size();
        long long ans = 0;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }

        vector<int> temp = prefix;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        int m = temp.size();
        vector<int> BIT(m + 1, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                BIT[idx]++;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += BIT[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };

        for (int x : prefix) {
            int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
            ans += query(idx - 1);
            update(idx);
        }

        return (int)ans;
    }
};
