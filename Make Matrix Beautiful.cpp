class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        
        int n = mat.size() , maxi = 0 , ans = 0 ;
        
        vector<int>rows(n , 0) , cols(n , 0) ;
        
        for(int i = 0 ; i < n ; i ++){
            int rsum = 0 , csum = 0 ;
            for(int j = 0 ; j < n ; j ++){
                rsum += mat[i][j] ;
                csum += mat[j][i] ;
            }
            rows[i] = rsum ;
            cols[i] = csum ;
            maxi = max({maxi , csum, rsum}) ;
        }
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                int resi = maxi - max(rows[i] , cols[j]) ;
                ans += resi ;
                rows[i] += resi ; 
                cols[j] += resi ;
            }
        }
        
        return ans ;
    }
};
