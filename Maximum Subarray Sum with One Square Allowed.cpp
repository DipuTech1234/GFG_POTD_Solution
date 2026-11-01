class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        long long noSquare = arr[0];
        long long oneSquare = 1LL * arr[0] * arr[0];
        long long ans = max(noSquare, oneSquare);

        for (int i = 1; i < arr.size(); i++) {
            long long x = arr[i];

            long long newOneSquare = max({
                x * x,
                oneSquare + x,
                noSquare + x * x
            });

            long long newNoSquare = max(x, noSquare + x);

            noSquare = newNoSquare;
            oneSquare = newOneSquare;

            ans = max({ans, noSquare, oneSquare});
        }

        return (int)ans;
    }
};
