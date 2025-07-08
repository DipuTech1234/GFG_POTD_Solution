#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && freqMap[arr[st.top()]] <= freqMap[arr[i]]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = arr[st.top()];
            }
            st.push(i);
        }
        
        return result;
    }
};
