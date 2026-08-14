class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        long long sum = s;
        vector<long long> v;
        v.push_back(s);

        for (int a : arr) {
            long long nxt = sum + a;
            if (nxt > x) break;

            v.push_back(nxt);
            sum += nxt;
        }

        for (int i = (int)v.size() - 1; i >= 0; --i) {
            if (v[i] <= x) {
                x -= v[i];
            }
            if (x == 0)
                return true;
        }

        return false;
    }
};
