class Solution {
    int ans;

    void dfs(Node* root, int len) {
        if (!root) return;

        ans = max(ans, len);

        if (root->left) {
            if (root->left->data == root->data + 1)
                dfs(root->left, len + 1);
            else
                dfs(root->left, 1);
        }

        if (root->right) {
            if (root->right->data == root->data + 1)
                dfs(root->right, len + 1);
            else
                dfs(root->right, 1);
        }
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;

        ans = 1;
        dfs(root, 1);

        return (ans == 1) ? -1 : ans;
    }
};
