
class Solution {
  public:
    int minFlips(string &s) {
        int n = s.size();
        int flips1 = 0, flips2 = 0;

        for (int i = 0; i < n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected1)
                flips1++;

            if (s[i] != expected2)
                flips2++;
        }

        return min(flips1, flips2);
    }
};
