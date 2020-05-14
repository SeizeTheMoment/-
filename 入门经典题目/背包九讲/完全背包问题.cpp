#include <iostream>
#include <cstdio>
#define MAX 1010
using namespace std;
int N,M;
int dp[MAX];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int v,w;
        scanf("%d%d",&v,&w);
        for(int j=v;j<=M;j++)
        {
            dp[j] = max(dp[j],dp[j-v]+w);
        }
    }
    printf("%d\n",dp[M]);
    
}
