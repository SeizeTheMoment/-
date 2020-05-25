class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        if(s[0]=='0')
            return 0;
        vector<int> dp(N+1,1);
        for(int i=1;i<N;i++)
        {
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2')
                    dp[i+1] = dp[i-1];
                else return 0;
            }
            else{
                int tmp = (s[i-1]-48)*10+s[i]-48;
                if(tmp>=10&&tmp<=26)
                    dp[i+1] = dp[i-1] + dp[i];
                else 
                    dp[i+1] = dp[i];
            }
        }s
        return dp[N];
    }
};