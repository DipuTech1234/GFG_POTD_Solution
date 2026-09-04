class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        long long sum = 0, ans = 0;
        
        for (int i = 0; i < n + m - 1; i++) {
            sum += arr[i % n];
            
            if (i >= m)
                sum -= arr[(i - m) % n];
            
            if (i >= m - 1)
                ans = max(ans, sum);
        }
        
        return (int)ans;
    }
};
