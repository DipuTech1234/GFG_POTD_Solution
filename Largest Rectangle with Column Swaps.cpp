class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        
        // hist[i][j] store consecutive 1s ending at mat[i][j] upwards
        vector<vector<int>> hist(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; i++) {
                if (mat[i][j] == 1) {
                    hist[i][j] = hist[i - 1][j] + 1;
                } else {
                    hist[i][j] = 0;
                }
            }
        }
        
        int max_area = 0;
        
        // For each row, sort the histogram heights in descending order to maximize width
        for (int i = 0; i < n; i++) {
            vector<int> count(n + 1, 0);
            for (int j = 0; j < m; j++) {
                count[hist[i][j]]++;
            }
            
            int curr_width = 0;
            for (int h = n; h >= 1; h--) {
                curr_width += count[h];
                max_area = max(max_area, curr_width * h);
            }
        }
        
        return max_area;
    }
};
