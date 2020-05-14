#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 2010
using namespace std;
int N,M;
int dp[MAX];
struct Good
{
    int v;
    int w;
};
int main()
{
    scanf("%d%d",&N,&M);
    vector<Good> goods;
    for(int i=1;i<=N;i++)
    {
        int v,w,s;
        scanf("%d%d%d",&v,&w,&s);
        for(int k=1;k<=s;k*=2)
        {
            s-=k;
            goods.push_back(Good{k*v,k*w});
        }
        if(s>0)
            goods.push_back(Good{s*v,s*w});
    }
    for(auto good : goods)
    {
        for(int j=M;j>=good.v;j--)
        {
            dp[j] = max(dp[j],dp[j-good.v]+good.w);
        }
    }
    printf("%d\n",dp[M]);
    return 0;
}
