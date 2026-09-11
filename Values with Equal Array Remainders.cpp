class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        
        int g = 0;
        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }
        
        if (g == 0)
            return -1;
        
        int ans = 0;
        for (int i = 1; 1LL * i * i <= g; i++) {
            if (g % i == 0) {
                ans++;
                if (i != g / i)
                    ans++;
            }
        }
        
        return ans;
    }
};
