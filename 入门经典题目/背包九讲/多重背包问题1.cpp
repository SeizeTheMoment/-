#include <iostream>
#include <cstdio>
#define MAX 110
using namespace std;

int N,M;
int dp[MAX];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int v,w,s;
        scanf("%d%d%d",&v,&w,&s);
        for(int j=M;j>=v;j--)
        {
            for(int k=0;k<=s&&k*v<=j;k++)
            {
                dp[j] = max(dp[j],dp[j-k*v]+k*w);
            }
        }
    }
    printf("%d\n",dp[M]);
}
