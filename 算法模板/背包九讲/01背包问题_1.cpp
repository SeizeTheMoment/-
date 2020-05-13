#include <iostream>
#include <cstdio>
#define MAX 1010
using namespace std;
int N,M;
int dp[MAX][MAX];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int v,w;
        scanf("%d%d",&v,&w);
        for(int j=0;j<=M;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-v>=0)
                dp[i][j] = max(dp[i][j],dp[i-1][j-v]+w);
        }
    }
    printf("%d\n",dp[N][M]);
    
}
