class Solution {
public:
    int minDiff(Node *root, int k) {
        int ans = INT_MAX;

        while (root != nullptr) {
            ans = min(ans, abs(root->data - k));

            if (root->data == k)
                return 0;
            else if (k < root->data)
                root = root->left;
            else
                root = root->right;
        }

        return ans;
    }
};
