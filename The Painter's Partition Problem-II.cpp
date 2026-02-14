class Solution {
  public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long curr = 0;

        for (int len : arr) {
            if (curr + len <= maxTime) {
                curr += len;
            } else {
                painters++;
                curr = len;
                if (painters > k)
                    return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for (int x : arr)
            high += x;

        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
