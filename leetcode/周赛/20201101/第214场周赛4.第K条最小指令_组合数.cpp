class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int Hcnt = destination[1];
        int Vcnt = destination[0];
        vector<vector<int>> comb(Vcnt+Hcnt, vector<int>(Hcnt));
        comb[0][0] = 1;
        for(int i=1; i < Vcnt+Hcnt; i++)
        {
            comb[i][0] = 1;
            for(int j = 1; j <=i && j < Hcnt; j++)
            {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
        string ans;
        int N = Hcnt+Vcnt;
        for(int i=0; i < N; i++)
        {
            if(Hcnt>0)
            {
                int num = comb[Hcnt+Vcnt-1][Hcnt-1];
                if(k>num)
                {
                    Vcnt--;
                    ans += 'V';
                    k -= num;
                }
                else{
                    ans += 'H';
                    Hcnt--;
                }
            }
            else {
                ans += 'V';
                Vcnt--;
            };
        }
        return ans;
    }
};
