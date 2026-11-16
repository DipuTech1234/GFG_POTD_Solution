class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        int low = 1;
        int high = k + arr.size();

        while (low < high) {
            int mid = low + (high - low) / 2;
            int removed = 0;

            for (int x : arr) {
                if (x <= mid) {
                    removed++;
                }
            }

            int remaining = mid - removed;

            if (remaining >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
