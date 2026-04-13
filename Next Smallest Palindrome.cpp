class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        // Step 1: Check if all digits are 9
        bool all9 = true;
        for (int x : num) {
            if (x != 9) {
                all9 = false;
                break;
            }
        }
        
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }
        
        vector<int> res = num;
        
        // Step 2: Mirror left to right
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
        
        while (i >= 0) {
            res[j++] = res[i--];
        }
        
        // Step 3: Check if mirrored number is greater
        if (res > num) return res;
        
        // Step 4: Increment middle and handle carry
        int carry = 1;
        i = mid - 1;
        
        if (n % 2 == 1) {
            res[mid] += carry;
            carry = res[mid] / 10;
            res[mid] %= 10;
            j = mid + 1;
        } else {
            j = mid;
        }
        
        while (i >= 0 && carry) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
            res[j++] = res[i--];
        }
        
        return res;
    }
};
