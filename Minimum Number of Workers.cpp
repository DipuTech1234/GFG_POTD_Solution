class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxReach(n, -1);

        // Build valid intervals ONLY for arr[i] >= 0
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                int left = max(0, i - arr[i]);
                int right = min(n - 1, i + arr[i]);
                maxReach[left] = max(maxReach[left], right);
            }
        }

        int men = 0;
        int currEnd = 0;
        int farthest = -1;
        int i = 0;

        while (currEnd < n) {
            while (i <= currEnd && i < n) {
                farthest = max(farthest, maxReach[i]);
                i++;
            }

            if (farthest < currEnd) {
                return -1;
            }

            men++;
            currEnd = farthest + 1;
        }

        return men;
    }
};
