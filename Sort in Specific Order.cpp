class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            if ((a % 2) != (b % 2))
                return a % 2 > b % 2;
            if (a % 2 == 1)
                return a > b;
            return a < b;
        });
    }
};
