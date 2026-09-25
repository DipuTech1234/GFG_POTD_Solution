#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        int n = height.size();

        struct Box {
            int x, y, h;
        };

        vector<Box> boxes;

        for (int i = 0; i < n; i++) {
            int a = height[i], b = width[i], c = length[i];

            boxes.push_back({max(b, c), min(b, c), a});
            boxes.push_back({max(a, c), min(a, c), b});
            boxes.push_back({max(a, b), min(a, b), c});
        }

        int m = boxes.size();
        vector<int> dp(m, 0);

        function<int(int)> solve = [&](int i) {
            if (dp[i] != 0)
                return dp[i];

            dp[i] = boxes[i].h;

            for (int j = 0; j < m; j++) {
                if (boxes[j].x > boxes[i].x &&
                    boxes[j].y > boxes[i].y) {
                    dp[i] = max(dp[i], boxes[i].h + solve(j));
                }
            }

            return dp[i];
        };

        int ans = 0;

        for (int i = 0; i < m; i++) {
            ans = max(ans, solve(i));
        }

        return ans;
    }
};
