class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int N = mat.size();
        int M  = mat[0].size();
        vector<int> sumi(N);
        vector<int> sumj(M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                sumi[i] += mat[i][j];
                sumj[j] += mat[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(mat[i][j]==1)
                {
                    if(sumi[i]==1&&sumj[j]==1)
                        ans++;
                }
            }
        }
        return ans;
        
    }
};
