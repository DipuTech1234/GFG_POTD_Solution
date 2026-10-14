class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (int r : roll) {
            diff[0]++;
            diff[r]--;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += diff[i];
            s[i] = 'a' + (s[i] - 'a' + count) % 26;
        }

        return s;
    }
};
