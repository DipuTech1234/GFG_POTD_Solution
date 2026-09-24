class Solution {
public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        vector<pair<int,int>> d;
        
        for (int i = 0; i < n; i++)
            d.push_back({r[i], h[i]});
        
        sort(d.begin(), d.end());
        
        const int MAXH = 1000;
        vector<int> bit(MAXH + 2, 0);
        
        auto query = [&](int x) {
            int ans = 0;
            while (x > 0) {
                ans = max(ans, bit[x]);
                x -= x & -x;
            }
            return ans;
        };
        
        auto update = [&](int x, int val) {
            while (x <= MAXH + 1) {
                bit[x] = max(bit[x], val);
                x += x & -x;
            }
        };
        
        int ans = 0;
        
        for (int i = 0; i < n; ) {
            int j = i;
            vector<pair<int,int>> pending;
            
            while (j < n && d[j].first == d[i].first) {
                int height = d[j].second;
                int cur = height + query(height - 1);
                pending.push_back({height, cur});
                ans = max(ans, cur);
                j++;
            }
            
            for (auto &[height, cur] : pending)
                update(height, cur);
            
            i = j;
        }
        
        return ans;
    }
};
