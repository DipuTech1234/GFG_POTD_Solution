class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans;
        
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != word[0]) continue;
                
                for (int d = 0; d < 8; d++) {
                    int x = i, y = j;
                    bool found = true;
                    
                    for (int k = 1; k < word.size(); k++) {
                        x += dx[d];
                        y += dy[d];
                        
                        if (x < 0 || x >= n || y < 0 || y >= m ||
                            mat[x][y] != word[k]) {
                            found = false;
                            break;
                        }
                    }
                    
                    if (found) {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
