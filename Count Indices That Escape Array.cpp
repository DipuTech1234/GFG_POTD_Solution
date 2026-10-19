class Solution {
public:
    int goodIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> vis(n, 0);
        vector<int> good(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 2) continue;

            vector<int> path;
            unordered_map<int, int> pos;
            int cur = i;

            while (cur >= 0 && cur < n && vis[cur] == 0 &&
                   !pos.count(cur)) {
                pos[cur] = path.size();
                path.push_back(cur);
                vis[cur] = 1;
                cur += arr[cur];
            }

            bool isGood = (cur < 0 || cur >= n);

            for (int j = (int)path.size() - 1; j >= 0; j--) {
                good[path[j]] = isGood;
                vis[path[j]] = 2;
            }

            if (cur >= 0 && cur < n && pos.count(cur)) {
                int cycleStart = pos[cur];

                for (int j = cycleStart; j < (int)path.size(); j++) {
                    good[path[j]] = 0;
                }

                for (int j = 0; j < cycleStart; j++) {
                    good[path[j]] = 0;
                }
            } else if (cur >= 0 && cur < n) {
                isGood = good[cur];

                for (int j = (int)path.size() - 1; j >= 0; j--) {
                    good[path[j]] = isGood;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += good[i];
        }

        return ans;
    }
};
