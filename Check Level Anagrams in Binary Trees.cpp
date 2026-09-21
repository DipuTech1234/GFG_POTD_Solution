class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2)
                return false;

            unordered_map<int, int> freq;

            for (int i = 0; i < n1; i++) {
                Node* a = q1.front();
                Node* b = q2.front();

                q1.pop();
                q2.pop();

                freq[a->data]++;
                freq[b->data]--;

                if (a->left)
                    q1.push(a->left);
                if (a->right)
                    q1.push(a->right);

                if (b->left)
                    q2.push(b->left);
                if (b->right)
                    q2.push(b->right);
            }

            for (auto &p : freq) {
                if (p.second != 0)
                    return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};
