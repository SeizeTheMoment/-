#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define MAX 12
using namespace std;

int N;
struct Node
{
    int lc;
    int rc;
}node[MAX];
bool isroot[MAX];
void bfs(int r)
{
    queue<int> que;
    que.push(r);
    bool space = false;
    while(!que.empty())
    {
         int next = que.front();
         que.pop();
         int lc = node[next].lc;
         int rc = node[next].rc;
         if(space)
             printf(" ");
         else space = true;
         printf("%d",next);
         if(rc>=0)
            que.push(rc);
         if(lc>=0)
            que.push(lc);
    }
    printf("\n");
}
bool inspace = false;
void inorder(int r)
{
    if(r<0)
       return;
    inorder(node[r].rc);
    if(inspace)
       printf(" ");
    else inspace = true;
    printf("%d",r);
    inorder(node[r].lc);
}
int main()
{
    scanf("%d",&N);
    fill(isroot,isroot+N,true);
    getchar();
    for(int i=0;i<N;i++)
    {
        char a,b;
        scanf("%c %c",&a,&b);
        if(a=='-') node[i].lc = -1;
        else{
            node[i].lc = int(a-48);
            isroot[node[i].lc] = false;
        }
        if(b=='-') node[i].rc = -1;
        else{
            node[i].rc = int(b-48);
            isroot[node[i].rc] = false;
        }
        getchar();
    }
    int root = 0;
    for(int i=0;i<N;i++)
    {
        if(isroot[i])
        {
             root = i;
             break;
        }
    }
    bfs(root);
    inorder(root);
    printf("\n");

    return 0;
}
