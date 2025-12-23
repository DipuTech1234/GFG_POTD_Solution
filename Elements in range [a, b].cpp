class Solution {
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Sort the array to enable binary search
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];
            
            // Find first index >= a
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            // Find first index > b, then subtract 1 to get last index <= b
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin() - 1;
            
            int count = 0;
            if (left <= right && left < arr.size() && right >= 0) {
                count = right - left + 1;
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};
