class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int str = 0 , enr = n-1 , stc = 0 , enc = m-1;
        while(ans.size() < n*m){
            for(int j=stc;j<=enc;j++){
                if(ans.size() == n*m){
                    break;
                }
                ans.push_back(mat[str][j]);
            }
            str++;
            for(int i=str;i<=enr;i++){
                if(ans.size() == n*m){
                    break;
                }
                ans.push_back(mat[i][enc]);
            }
            enc--;
            for(int j=enc;j>=stc;j--){
                if(ans.size() == n*m){
                    break;
                }
                ans.push_back(mat[enr][j]);
            }
            enr--;
            for(int i=enr;i>=str;i--){
                if(ans.size() == n*m){
                    break;
                }
                ans.push_back(mat[i][stc]);
            }
            stc++;
        }        
        return ans;
    }
};
 
