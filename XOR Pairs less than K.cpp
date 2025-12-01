class Solution {
  public:
    
    struct TrieNode {
        TrieNode* left;
        TrieNode* right;
        int cnt;
        TrieNode() {
            left = right = NULL;
            cnt = 0;
        }
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 15; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (bit == 0) {
                if (!cur->left)
                    cur->left = new TrieNode();
                cur = cur->left;
            } else {
                if (!cur->right)
                    cur->right = new TrieNode();
                cur = cur->right;
            }
            
            cur->cnt++;
        }
    }
    
    int query(int num, int k) {
        TrieNode* cur = root;
        int ans = 0;
        
        for (int i = 15; i >= 0; i--) {
            if (!cur) break;
            
            int bitNum = (num >> i) & 1;
            int bitK   = (k >> i) & 1;
            
            if (bitK == 1) {
                if (bitNum == 0 && cur->left)
                    ans += cur->left->cnt;
                if (bitNum == 1 && cur->right)
                    ans += cur->right->cnt;
                
                cur = (bitNum == 0) ? cur->right : cur->left;
            } else {
                cur = (bitNum == 0) ? cur->left : cur->right;
            }
        }
        
        return ans;
    }

    int cntPairs(vector<int>& arr, int k) {
        int result = 0;
        
        for (int x : arr) {
            result += query(x, k);
            insert(x);
        }
        
        return result;
    }
};
