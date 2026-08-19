class Solution {
  private:
    int countTripletsLessThanOrEqual(vector<int>& arr, int val) {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] <= val) {
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }

  public:
    int countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());
        return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
    }
};
