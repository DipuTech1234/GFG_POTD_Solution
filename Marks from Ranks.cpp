class Solution {
public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();
        vector<long long> pref(n);
        pref[0] = (long long)r[0] - l[0] + 1;
        
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (long long)r[i] - l[i] + 1;
        }
        
        vector<int> ans;
        
        for (int x : rank) {
            int lo = 0, hi = n - 1;
            
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (pref[mid] >= x)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            
            long long before = (lo == 0 ? 0 : pref[lo - 1]);
            long long mark = (long long)l[lo] + (x - before - 1);
            ans.push_back((int)mark);
        }
        
        return ans;
    }
};
