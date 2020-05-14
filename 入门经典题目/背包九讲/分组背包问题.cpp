#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1010
using namespace std;
int N,M;
int dp[MAX];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int S;
        scanf("%d",&S);
        vector<int> v,w;
        v.resize(S);
        w.resize(S);
        for(int k=0;k<S;k++)
            scanf("%d%d",&v[k],&w[k]);
        for(int j=M;j>=0;j--)
            for(int k=0;k<S;k++)
                if(j-v[k]>=0)
                    dp[j] = max(dp[j],dp[j-v[k]]+w[k]);
                
    }
    printf("%d\n",dp[M]);
}
