class Solution {
public:
    bool findPattern(string& s) {
        int i = 0;
        int n = s.size();

        while (i < n) {
            int xCount = 0, yCount = 0;

            while (i < n && s[i] == 'x') {
                xCount++;
                i++;
            }

            while (i < n && s[i] == 'y') {
                yCount++;
                i++;
            }

            if (xCount == 0 || xCount != yCount) {
                return false;
            }
        }

        return true;
    }
};
