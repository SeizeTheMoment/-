#include <iostream>
#include <cstdio>
#define MAX 1010
using namespace std;
const int MOD = 1e9+7;
int dp[MAX], g[MAX];
int N,M;
int main()
{
    scanf("%d%d",&N,&M);
    dp[0] = 0;
    g[0] = 1;
    for(int i=1;i<=M;i++)
        dp[i] = -0x3f3f3f3f;
    for(int i=0;i<N;i++)
    {
        int v,w;
        scanf("%d%d",&v,&w);
        for(int j=M;j>=v;j--)
        {
            int maxi = max(dp[j],dp[j-v]+w);
            int sum = 0;
            if(maxi==dp[j])
                sum+=g[j];
            if(maxi==dp[j-v]+w)
                sum+=g[j-v];
            dp[j] = maxi;
            sum%=MOD;
            g[j] = sum;
        }
    }
    int maxians = 0;
    for(int i=0;i<=M;i++)
        maxians = max(maxians,dp[i]);
    int res = 0;
    for(int i=0;i<=M;i++)
    {
        if(dp[i]==maxians)
        {
            res+=g[i];
            res%=MOD;
        }
    }
    printf("%d\n",res);
}
