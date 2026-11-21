class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        int sum = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > x) {
                ans = min(ans, right - left + 1);
                sum -= arr[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};
