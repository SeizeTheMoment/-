class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int N = matrix.size();
        if(N==0)
            return ans;
        int M = matrix[0].size();
        ans.resize(N*M);
        int le = 0;
        int ri = M-1;
        int to = 0;
        int bo = N-1;
        int i=0;
        int j=0;
        int k = 0;
        int dx[4] ={0,1,0,-1};
        int dy[4] ={1,0,-1,0};
        int direction = 0;
        while(k<N*M)
        {
            ans[k++] = matrix[i][j];
            if(direction==0&&j==ri)
            {
                direction = 1;
            }
            else if(direction==1&&i==bo)
            {
                direction = 2;
            }
            else if(direction==2&&j==le)
            {
                direction = 3;
            }
            else if(direction==3&&i==to+1)
            {
                direction = 0;
                to++;
                bo--;
                le++;
                ri--;
            }
            i+=dx[direction];
            j+=dy[direction];
        }
        return ans;
    }
};