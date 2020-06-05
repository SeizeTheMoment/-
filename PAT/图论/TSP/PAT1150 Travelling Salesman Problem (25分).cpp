#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
#define MAX 210

using namespace std;
int graph[MAX][MAX];
int N,M;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            graph[i][j] = INF;
    for(int i=0;i<M;i++)
    {
        int city1,city2,dist;
        scanf("%d%d%d",&city1,&city2,&dist);
        graph[city1][city2] = dist;
        graph[city2][city1] = dist;
    }
    int K;
    scanf("%d",&K);
    int ans = INF;
    int ansind = 0;
    for(int j=0;j<K;j++)
    {
        int n;
        scanf("%d",&n);
        vector<int> path;        
        //set<int> s;
        vector<int> vis;
        vis.resize(N+1);
        for(int t=0;t<n;t++)
        {
            int x;
            scanf("%d",&x);
            path.push_back(x);
            vis[x] = true;
        }
        bool flag = true;
        for(int i=1;i<=N;i++)
        {
            if(!vis[i])
                flag = false;
        }
        printf("Path %d: ",j+1);
        int sum=0;
        for(int p=1;p<path.size();p++)
        {
            if(graph[path[p]][path[p-1]]==INF)
            {
                flag = false;
                sum = -1;
                break;
            }
            sum += graph[path[p]][path[p-1]];
        }
        if(sum<0)
        {
            printf("NA (Not a TS cycle)\n");
        }
        else{
            if(path.front()!=path.back()||n<N+1)
                printf("%d (Not a TS cycle)\n",sum);
            else if(flag==false)
                printf("%d (Not a TS cycle)\n",sum);
            else{
                if(sum<ans)
                {
                    ans = sum;
                    ansind = j+1;
                }
                if(n==N+1)
                    printf("%d (TS simple cycle)\n",sum);
                else printf("%d (TS cycle)\n",sum);
            }
        }
        
    }
    printf("Shortest Dist(%d) = %d\n",ansind,ans);
    return 0;
}
