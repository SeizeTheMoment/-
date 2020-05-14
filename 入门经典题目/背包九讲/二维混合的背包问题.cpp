#include <iostream>
#include <cstdio>
#define MAX 1010
using namespace std;
int N,V,M;
int dp[MAX][MAX];
int main()
{
    scanf("%d%d%d",&N,&V,&M);
    for(int i=1;i<=N;i++)
    {
        int v,m,w;
        scanf("%d%d%d",&v,&m,&w);
        for(int j=V;j>=v;j--)
        {
            for(int k=M;k>=m;k--)
            {
                dp[j][k] = max(dp[j][k],dp[j-v][k-m]+w);
            }
        }
    }
    printf("%d\n",dp[V][M]);
    return 0;
}
