class Solution {
public:
    long long ans;
    int leaves;

    long long dfs(Node* root) {
        if (!root) return LLONG_MIN / 4;

        if (!root->left && !root->right) {
            leaves++;
            return root->data;
        }

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        if (root->left && root->right) {
            ans = max(ans, left + root->data + right);
        }

        if (!root->left)
            return root->data + right;

        if (!root->right)
            return root->data + left;

        return root->data + max(left, right);
    }

    int maxPathSum(Node *root) {
        ans = LLONG_MIN;
        leaves = 0;

        if (!root) return -1;

        dfs(root);

        if (leaves < 2) return -1;

        return (int)ans;
    }
};
