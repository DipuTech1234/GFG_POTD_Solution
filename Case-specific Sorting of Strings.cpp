class Solution {
public:
    string caseSort(string& s) {
        string temp = s;
        sort(temp.begin(), temp.end());
        int upper_pos = 0;
        int lower_pos = 0;
        
        // Find the first lowercase letter in the sorted string
        while (lower_pos < temp.size() && isupper(temp[lower_pos])) {
            lower_pos++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                s[i] = temp[upper_pos++];
            } else {
                s[i] = temp[lower_pos++];
            }
        }
        return s;
    }
};
