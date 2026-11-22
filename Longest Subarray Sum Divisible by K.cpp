class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = 0;

        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            int rem = ((sum % k) + k) % k;

            if (mp.find(rem) != mp.end()) {
                ans = max(ans, i - mp[rem]);
            } else {
                mp[rem] = i;
            }
        }

        return ans;
    }
};
