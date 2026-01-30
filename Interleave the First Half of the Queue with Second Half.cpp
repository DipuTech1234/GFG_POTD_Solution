class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        if (n % 2 != 0) return;

        queue<int> firstHalf;
        int half = n / 2;

        // Move first half into firstHalf queue
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Interleave first half and second half
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
