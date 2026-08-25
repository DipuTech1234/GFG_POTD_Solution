#include <bits/stdc++.h> using namespace std;

class Solution { public: int minMoves(vector<int>& arr) { int n = arr.size(); vector<int> pos(n + 1);

for (int i = 0; i < n; ++i)
        pos[arr[i]] = i;

    int longest = 1, cur = 1;

    for (int x = 1; x < n; ++x) {
        if (pos[x] < pos[x + 1])
            ++cur;
        else
            cur = 1;

        longest = max(longest, cur);
    }

    return n - longest;
}

};
