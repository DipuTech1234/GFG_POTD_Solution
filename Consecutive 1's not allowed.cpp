class Solution {
public:
    int countStrings(int n) {
        if (n == 1) return 2;
        if (n == 2) return 3;

        int prev2 = 2; // f(1)
        int prev1 = 3; // f(2)
        int curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
