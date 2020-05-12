#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
int N,M;
int K;
struct Node
{
    int x;
    int y;
};
vector<Node> edge;
int main()
{
    scanf("%d%d",&N,&M);
    while(M--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        edge.push_back(Node{x,y});
    }
    scanf("%d",&K);
    while(K--)
    {
        int k;
        scanf("%d",&k);
        set<int> cover;
        for(int i=0;i<k;i++)
        {
            int x;
            scanf("%d",&x);
            cover.insert(x);
        }
        bool flag = true;
        for(int i=0;i<edge.size();i++)
        {
            if(cover.find(edge[i].x)!=cover.end())
            {
                continue;
            }
            if(cover.find(edge[i].y)!=cover.end())
            {
                continue;
            }
            flag = false;
            break;
        }
        if(flag)
            printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}