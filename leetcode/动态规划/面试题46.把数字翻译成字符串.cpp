class Solution {
public:
    int translateNum(int num) {
        stringstream ss;
        ss<<num;
        string s = ss.str();
        int N = s.length();
        vector<int> dp;
        dp.resize(N+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=N;i++)
        {

            int val = (s[i-2]-48)*10+s[i-1]-48;
            if(val>=10&&val<=25)
            {
                dp[i] = dp[i-1]+dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[N];
    }
};
