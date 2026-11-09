class Solution {
  public:
    int getCount(string &s, int k) {
        int count[26] = {0};

        for (int i = 0; i < s.size(); ) {
            char ch = s[i];
            count[ch - 'a']++;

            while (i < s.size() && s[i] == ch) {
                i++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == k) {
                ans++;
            }
        }

        return ans;
    }
};
