class Solution {
public:
    int findMax(int n) {
        int ans = n, maxSum = 0;
        
        auto digitSum = [](int x) {
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };
        
        maxSum = digitSum(n);
        
        int p = 1;
        while (p <= n) {
            int digit = (n / p) % 10;
            
            if (digit > 0) {
                int candidate = (n / (p * 10)) * (p * 10) + (digit - 1) * p + (p - 1);
                int sum = digitSum(candidate);
                
                if (sum > maxSum || (sum == maxSum && candidate > ans)) {
                    maxSum = sum;
                    ans = candidate;
                }
            }
            
            p *= 10;
        }
        
        return ans;
    }
};
