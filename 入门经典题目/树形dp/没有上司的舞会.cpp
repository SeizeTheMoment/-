#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 6010
using namespace std;
int dp[MAX][2];
int N;
int happiness[MAX];
vector<int> edge[MAX];
void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = happiness[u];
    for(int v:edge[u])
    {
        dfs(v);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
/* 
    
*/
int boss[MAX];
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&happiness[i]);
   
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        edge[y].push_back(x);
        boss[x] = y;
    }
    int root = 1;
    for(int i=1;i<=N;i++)
    {
        if(boss[i]==0)
        {
            dfs(i);
            root = i;
            break;
        }
    }
    printf("%d\n",max(dp[root][0],dp[root][1]));
    getchar();
    getchar();

}