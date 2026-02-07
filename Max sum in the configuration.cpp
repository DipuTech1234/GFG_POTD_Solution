class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        int arrSum = 0;
        int currVal = 0;

        // initial sums
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }

        int result = currVal;

        // compute other rotations
        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - i];
            result = max(result, currVal);
        }

        return result;
    }
};
