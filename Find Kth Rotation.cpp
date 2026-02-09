class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            // If array is already sorted
            if (arr[low] <= arr[high]) {
                return low;
            }
            
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            
            // Check if mid is minimum
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                return mid;
            }
            
            // Left part is sorted, go right
            if (arr[mid] >= arr[low]) {
                low = mid + 1;
            }
            // Right part is sorted, go left
            else {
                high = mid - 1;
            }
        }
        
        return 0;
    }
};
