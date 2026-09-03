class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        
        long long keep = 0, replace = 0;
        
        for (int i = 1; i < n; i++) {
            long long nk = max(
                keep + abs(arr[i] - arr[i - 1]),
                replace + abs(arr[i] - 1)
            );
            
            long long nr = max(
                keep + abs(1 - arr[i - 1]),
                replace
            );
            
            keep = nk;
            replace = nr;
        }
        
        return (int)max(keep, replace);
    }
};
