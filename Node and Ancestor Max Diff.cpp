class Solution {
  private:
    int solve(Node* root, int &max_diff) {
        if (root == nullptr) {
            return INT_MAX;
        }

        // If it's a leaf node, it has no descendants
        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        // Find the minimum value in left and right subtrees
        int left_min = solve(root->left, max_diff);
        int right_min = solve(root->right, max_diff);

        int min_child = std::min(left_min, right_min);

        // Update the maximum difference (Ancestor - Descendant)
        max_diff = std::max(max_diff, root->data - min_child);

        // Return minimum value in the subtree rooted at the current node
        return std::min(root->data, min_child);
    }

  public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        solve(root, max_diff);
        return max_diff;
    }
};
