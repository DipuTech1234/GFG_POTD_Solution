class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int swapCnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == i + 1) continue;
            while(arr[i] != i + 1) {
                swap(arr[arr[i] - 1], arr[i]);
                swapCnt++;
            }
        }
        return (swapCnt == 2 || swapCnt == 0);
    }
};
