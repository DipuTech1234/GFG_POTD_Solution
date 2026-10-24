class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        int x = 0, y = 0;
        int minX = 0, maxX = 0;
        int minY = 0, maxY = 0;

        for (char c : s) {
            if (c == 'L') y--;
            else if (c == 'R') y++;
            else if (c == 'U') x--;
            else if (c == 'D') x++;

            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }

        return (maxX - minX < n) && (maxY - minY < m);
    }
};
