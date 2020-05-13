#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1010
using namespace std;
struct Good
{
    int v;
    int w;
    int s;
};
int N,M;
int dp[MAX];
int main()
{
    scanf("%d%d",&N,&M);
    vector<Good> goods;
    for(int i=1;i<=N;i++)
    {
        int v,w,s;
        scanf("%d%d%d",&v,&w,&s);
        if(s<=0)
            goods.push_back(Good{v,w,s});
        else{
            for(int k=1;k<=s;k*=2)
            {
                s-=k;
                goods.push_back(Good{k*v,k*w,-1});
            }
            if(s>0)
                goods.push_back(Good{s*v,s*w,-1});
        }
    }
    for(auto good : goods)
    {
        if(good.s<0)
        {
            for(int j=M;j>=good.v;j--)
                dp[j] = max(dp[j],dp[j-good.v]+good.w);
        }
        else{
            for(int j=good.v;j<=M;j++)
                dp[j] = max(dp[j],dp[j-good.v]+good.w);
        }
    }
    printf("%d\n",dp[M]);
}
