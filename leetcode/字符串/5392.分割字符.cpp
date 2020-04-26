class Solution {
public:
    int maxScore(string s) {
        int N = s.length();
        vector<int> dp0,dp1;
        dp0.resize(N);
        dp1.resize(N);
        for(int i =0;i<N;i++)
        {
            if(i==0)
            {
                dp0[0] = 0;
                dp1[0] = 0;
            }
            else{
                dp0[i] = dp0[i-1];
                dp1[i] = dp1[i-1];
            }
            if(s[i]=='0')
                dp0[i] ++;
            else dp1[i]++;
        }
        int maxi = 0;
        for(int i=0;i<N-1;i++)
        {
            if(dp0[i]+(dp1[N-1]-dp1[i])>maxi)
            {
                maxi = dp0[i]+dp1[N-1]-dp1[i];
            }
        }
        return maxi;
    }
};
