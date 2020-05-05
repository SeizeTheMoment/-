#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 210
using namespace std;
int N,M;
int graph[MAX][MAX];
bool judge(vector<int> vec)
{
    vector<bool> exist;
    exist.resize(vec.size());
    if(vec[0]!=vec[vec.size()-1])
        return false;
    for(int i=1;i<vec.size();i++)
    {
        if(!graph[vec[i-1]][vec[i]])
        {
            return false;
        }
        if(exist[vec[i]])
            return false;
        exist[vec[i]] = true;
    }
    return true;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int k;
        scanf("%d",&k);
        vector<int> vec;
        vec.resize(k);
        for(int i=0;i<k;i++)
        {
            int x;
            scanf("%d",&vec[i]);
        }
        if(k!=N+1)
            printf("NO\n");
        else{
            if(judge(vec))
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}