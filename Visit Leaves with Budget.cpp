class Solution {
public:
    void dfs(Node* root, int level, vector<int>& v) {
        if (!root) return;

        if (!root->left && !root->right) {
            v.push_back(level);
            return;
        }

        dfs(root->left, level + 1, v);
        dfs(root->right, level + 1, v);
    }

    int getCount(Node* root, int k) {
        vector<int> v;
        dfs(root, 1, v);

        sort(v.begin(), v.end());

        int ans = 0;
        for (int cost : v) {
            if (cost > k)
                break;

            k -= cost;
            ans++;
        }

        return ans;
    }
};
