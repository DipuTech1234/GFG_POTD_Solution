class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        if (knightPos == targetPos) return 0;

        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

        queue<pair<pair<int, int>, int>> q;

        q.push({{knightPos[0], knightPos[1]}, 0});
        visited[knightPos[0]][knightPos[1]] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.first.first;
            int y = cur.first.second;
            int steps = cur.second;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n &&
                    !visited[nx][ny]) {

                    if (nx == targetPos[0] && ny == targetPos[1])
                        return steps + 1;

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
    }
};
