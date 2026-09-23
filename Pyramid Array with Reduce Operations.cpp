class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n), right(n);
        
        left[0] = 1;
        for (int i = 1; i < n; i++)
            left[i] = min(arr[i], left[i - 1] + 1);
        
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            right[i] = min(arr[i], right[i + 1] + 1);
        
        long long total = 0;
        int maxHeight = 0;
        
        for (int x : arr)
            total += x;
        
        for (int i = 0; i < n; i++) {
            int height = min({left[i], right[i], i + 1, n - i});
            maxHeight = max(maxHeight, height);
        }
        
        long long kept = 1LL * maxHeight * maxHeight;
        return (int)(total - kept);
    }
};
