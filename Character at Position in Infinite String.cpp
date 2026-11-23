class Solution {
public:
    char posInfinite(string &s, int pos) {
        long long p = pos;
        vector<long long> len;

        len.push_back(s.size());

        int i = 1;
        while (len.back() < p) {
            long long nxt = 2 * len.back() + i;
            len.push_back(nxt);
            i++;
        }

        for (int j = len.size() - 1; j > 0; j--) {
            long long prev = len[j - 1];
            long long mid = j;

            if (p <= prev) {
                continue;
            }
            else if (p <= prev + mid) {
                return '$';
            }
            else {
                p = 2 * prev + mid - p + 1;
            }
        }

        return s[p - 1];
    }
};
