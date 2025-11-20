class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));
        
        // Initialize distance matrix
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0; // cost to transform a character to itself is 0
        }
        
        // Add given transformations
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int totalCost = 0;
        int n = s.length();
        
        // For each character position
        for (int i = 0; i < n; i++) {
            int charS = s[i] - 'a';
            int charT = t[i] - 'a';
            
            if (charS == charT) {
                continue; // characters already match
            }
            
            int minCostForPosition = INF;
            
            // Try to transform both characters to a common target character
            for (int target = 0; target < 26; target++) {
                if (dist[charS][target] < INF && dist[charT][target] < INF) {
                    minCostForPosition = min(minCostForPosition, 
                                           dist[charS][target] + dist[charT][target]);
                }
            }
            
            if (minCostForPosition == INF) {
                return -1; // no common target found
            }
            
            totalCost += minCostForPosition;
        }
        
        return totalCost;
    }
};
