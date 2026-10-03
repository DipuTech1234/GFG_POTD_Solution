class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        int N = 4 * n;
        int total = N * N;

        vector<int> coil1;

        for (int ring = 0; ring < N / 2; ring++) {
            int lo = ring;
            int hi = N - 1 - ring;

            if (ring % 2 == 0) {
                // Down along left side
                for (int r = lo; r <= hi; r++)
                    coil1.push_back(r * N + lo + 1);

                // Right along bottom
                for (int c = lo + 1; c < hi; c++)
                    coil1.push_back(hi * N + c + 1);
            }
            else {
                // Up along right side
                for (int r = hi; r >= lo; r--)
                    coil1.push_back(r * N + hi + 1);

                // Left along top
                for (int c = hi - 1; c > lo; c--)
                    coil1.push_back(lo * N + c + 1);
            }
        }

        vector<int> coil2;

        // Coil 2 is the 180-degree counterpart of coil 1
        for (int x : coil1)
            coil2.push_back(total + 1 - x);

        return {coil1, coil2};
    }
};
