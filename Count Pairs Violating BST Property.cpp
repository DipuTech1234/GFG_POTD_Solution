
class Solution {
public:
    long long ans;

    vector<int> solve(Node* root) {
        if (root == nullptr)
            return {};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        ans += left.end() - upper_bound(left.begin(), left.end(), root->data);
        ans += lower_bound(right.begin(), right.end(), root->data) - right.begin();

        for (int x : left) {
            ans += lower_bound(right.begin(), right.end(), x) - right.begin();
        }

        vector<int> res;
        res.reserve(left.size() + right.size() + 1);

        merge(left.begin(), left.end(),
              right.begin(), right.end(),
              back_inserter(res));

        res.insert(lower_bound(res.begin(), res.end(), root->data),
                   root->data);

        return res;
    }

    int pairsViolatingBST(Node* root) {
        ans = 0;
        solve(root);
        return (int)ans;
    }
};
