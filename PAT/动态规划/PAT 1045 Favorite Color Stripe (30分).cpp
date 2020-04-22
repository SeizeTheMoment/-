#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define MAX 10100
int N,M,L;
int fav[210];
int stripe[MAX];
int dp[210][MAX];
int main()
{
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i=1;i<=M;i++)
        scanf("%d",&fav[i]);
    scanf("%d",&L);
    for(int i=1;i<=L;i++)
        scanf("%d",&stripe[i]);
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=L;j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]);
            if(stripe[j]==fav[i])
                dp[i][j]++;
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    cout<<dp[M][L]<<endl;
    return 0;
}
