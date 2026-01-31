class kQueues {
    int *arr;        // Array of size n to store queue elements
    int *front;      // Array of size k to store front indices
    int *rear;       // Array of size k to store rear indices
    int *next;       // Array of size n to store next entry for each element
    int freeSpot;    // Index of first free slot in arr
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize next array as linked list of free slots
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0; // First free slot is 0
    }

    bool enqueue(int x, int qi) {
        if (freeSpot == -1) {
            return false; // No free space
        }

        int index = freeSpot;      // Get the free slot
        freeSpot = next[index];    // Update freeSpot to next free slot

        // If first element in queue qi
        if (front[qi] == -1) {
            front[qi] = index;
        } else {
            // Link previous rear to new node
            next[rear[qi]] = index;
        }

        next[index] = -1;          // End of queue
        rear[qi] = index;          // Update rear
        arr[index] = x;            // Insert element
        return true;
    }

    int dequeue(int qi) {
        if (front[qi] == -1) {
            return -1; // Queue is empty
        }

        int index = front[qi];      // Get front index
        front[qi] = next[index];    // Move front to next

        // Add the freed slot to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    bool isEmpty(int qi) {
        return front[qi] == -1;
    }

    bool isFull() {
        return freeSpot == -1;
    }

    ~kQueues() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};
