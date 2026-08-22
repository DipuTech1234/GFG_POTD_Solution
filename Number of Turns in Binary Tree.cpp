class Solution {
    bool findPath(Node* root, int x, string& path) {
        if (!root) return false;

        if (root->data == x) return true;

        path.push_back('L');
        if (findPath(root->left, x, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, x, path))
            return true;
        path.pop_back();

        return false;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {
        string pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        int i = 0;

        // Find common path up to LCA
        while (i < pathP.size() &&
               i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        string path;

        // p -> LCA
        // For upward movement, use the side from which we came.
        for (int j = pathP.size() - 1; j >= i; j--) {
            path += pathP[j];
        }

        // LCA -> q
        for (int j = i; j < pathQ.size(); j++) {
            path += pathQ[j];
        }

        // Same node / no movement
        if (path.empty())
            return -1;

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        // GFG expects -1 when there is no turn
        return turns == 0 ? -1 : turns;
    }
};
