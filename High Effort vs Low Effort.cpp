class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        
        long long noTask = 0;
        long long low = l[0];
        long long high = h[0];
        
        for (int i = 1; i < n; i++) {
            long long prevMax = max({noTask, low, high});
            
            long long newNoTask = prevMax;
            long long newLow = prevMax + l[i];
            long long newHigh = noTask + h[i];
            
            noTask = newNoTask;
            low = newLow;
            high = newHigh;
        }
        
        return (int)max({noTask, low, high});
    }
};
