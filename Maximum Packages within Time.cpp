class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (right - left + 1 > totalTime) {
                sum -= arr[left];
                left++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
