class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        int edges = 0;
        for (int i = 0; i < adj.size(); i++) {
            edges += adj[i].size();
        }
        return edges / 2;
    }
};
