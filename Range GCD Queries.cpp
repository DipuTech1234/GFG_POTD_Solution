class Solution {
    vector<int> seg;
    int n;

    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2 * idx, l, mid);
        build(arr, 2 * idx + 1, mid + 1, r);

        seg[idx] = gcd(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);

        seg[idx] = gcd(seg[2 * idx], seg[2 * idx + 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        return gcd(
            query(2 * idx, l, mid, ql, qr),
            query(2 * idx + 1, mid + 1, r, ql, qr)
        );
    }

public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        seg.resize(4 * n);

        build(arr, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 0) {
                ans.push_back(query(1, 0, n - 1, q[1], q[2]));
            } else {
                update(1, 0, n - 1, q[1], q[2]);
            }
        }

        return ans;
    }
};
