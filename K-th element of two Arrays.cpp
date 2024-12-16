class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<int,vector<int>,greater<>> pq;
        for(auto it:a) pq.push(it);
        for(auto it:b) pq.push(it);
        
        for(int i=0;i<k;i++){
            
            if(i==k-1) return pq.top();
            pq.pop();
        }
        return 0;
    }
};