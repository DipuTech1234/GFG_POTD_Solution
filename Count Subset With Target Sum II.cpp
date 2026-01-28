class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int n1 = n / 2;
        int n2 = n - n1;

        vector<long long> leftSums, rightSums;

        // Generate all subset sums for left half
        for (int mask = 0; mask < (1 << n1); mask++) {
            long long sum = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i))
                    sum += arr[i];
            }
            leftSums.push_back(sum);
        }

        // Generate all subset sums for right half
        for (int mask = 0; mask < (1 << n2); mask++) {
            long long sum = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i))
                    sum += arr[n1 + i];
            }
            rightSums.push_back(sum);
        }

        sort(rightSums.begin(), rightSums.end());

        long long count = 0;
        for (long long s : leftSums) {
            long long need = k - s;
            count += upper_bound(rightSums.begin(), rightSums.end(), need) -
                     lower_bound(rightSums.begin(), rightSums.end(), need);
        }

        return (int)count;
    }
};
