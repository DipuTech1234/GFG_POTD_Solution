class Solution {
  public:
    int minComputation(vector<int>& files) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int file : files) {
            pq.push(file);
        }

        int totalCost = 0;

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int cost = first + second;
            totalCost += cost;

            pq.push(cost);
        }

        return totalCost;
    }
};
