class Solution {
public:
    int minProd(vector<int>& arr) {
        long long product = 1;
        int negativeCount = 0;
        int largestNegative = INT_MIN;
        int smallestPositive = INT_MAX;
        bool zero = false;

        for (int x : arr) {
            if (x < 0) {
                negativeCount++;
                largestNegative = max(largestNegative, x);
                product *= x;
            }
            else if (x == 0) {
                zero = true;
            }
            else {
                smallestPositive = min(smallestPositive, x);
                product *= x;
            }
        }

        if (negativeCount == 0) {
            if (zero) return 0;
            return smallestPositive;
        }

        if (negativeCount % 2 == 0) {
            product /= largestNegative;
        }

        return (int)product;
    }
};
