class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};
