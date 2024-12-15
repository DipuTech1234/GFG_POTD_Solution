class Solution {
  public:
    int peakElement(vector<int>& arr){
        int n = arr.size(), low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid + 1]){
                low = mid + 1;
            }
            else{
                high =  mid;
            }
        }
        return low;
    }
};
