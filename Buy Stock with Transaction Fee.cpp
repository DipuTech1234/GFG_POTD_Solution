class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return 0;

        int hold = -arr[0];  // Buying first stock
        int cash = 0;        // No stock, no profit

        for(int i = 1; i < n; i++) {
            hold = max(hold, cash - arr[i]);         // Buy or keep holding
            cash = max(cash, hold + arr[i] - k);     // Sell or do nothing
        }

        return cash;
    }
};
