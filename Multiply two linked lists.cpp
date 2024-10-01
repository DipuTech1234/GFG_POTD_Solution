class solution {
  public:
  int mod = 1000000007;
    long long multiplyTwoLists(Node *first, Node *second) {
        long long ans = 0;
        long long s1 = 0, s2 = 0;
        while(first != NULL){
            s1 = (s1*10 + first->data)%mod;
            first = first->next;
        }
         while(second != NULL){
            s2 = (s2*10 + second->data)%mod;
            second = second->next;
        }
        ans = (s1 * s2)%mod;
        return ans;
    }
};
