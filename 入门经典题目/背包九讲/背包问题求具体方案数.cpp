#include <iostream>
#include <cstdio>
#define MAX 1010
using namespace std;
int N,M;
int dp[MAX][MAX];
int v[MAX],w[MAX];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d%d",&v[i],&w[i]);
    for(int i=N;i>=1;i--)
    {
        for(int j=1;j<=M;j++)
        {
            dp[i][j] = dp[i+1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    int vol = M;
    for(int i=1;i<=N;i++)
    {
        if(vol-v[i]>=0)
        {
            //此条件为true意味着选中了i
            if(dp[i][vol] == dp[i+1][vol-v[i]]+w[i])
            {
                if(vol!=M)
                    printf(" ");
                vol-=v[i];
                printf("%d",i);
            }
        }
        
    }
    printf("\n");
}
