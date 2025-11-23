class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        
        vector<int> parent(maxRow + maxCol + 2, -1);
        unordered_map<int, int> stoneNodes;
        
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + maxRow + 1;
            
            unionSets(row, col, parent);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }
        
        int components = 0;
        for (auto& node : stoneNodes) {
            if (find(node.first, parent) == node.first) {
                components++;
            }
        }
        
        return n - components;
    }
    
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] == -1) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y, vector<int>& parent) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};
