class Solution {
public:
    int absDiff(Node *root) {
        int ans = INT_MAX;
        Node* prev = nullptr;

        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;

            inorder(node->left);

            if (prev)
                ans = min(ans, node->data - prev->data);

            prev = node;

            inorder(node->right);
        };

        inorder(root);
        return ans;
    }
};
