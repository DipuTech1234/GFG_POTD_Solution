class Solution {
public:
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> a, b, ans;

        function<void(Node*)> inorder1 = [&](Node* root) {
            if (!root) return;
            inorder1(root->left);
            a.push_back(root->data);
            inorder1(root->right);
        };

        function<void(Node*)> inorder2 = [&](Node* root) {
            if (!root) return;
            inorder2(root->left);
            b.push_back(root->data);
            inorder2(root->right);
        };

        inorder1(r1);
        inorder2(r2);

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
