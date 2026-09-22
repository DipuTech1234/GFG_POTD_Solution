class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        vector<vector<int>> pos(26);

        for (int i = 0; i < (int)s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string ans = "";

        for (string &word : d) {
            int cur = -1;
            bool possible = true;

            for (char c : word) {
                auto &v = pos[c - 'a'];
                auto it = upper_bound(v.begin(), v.end(), cur);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                cur = *it;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
