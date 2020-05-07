#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N;
struct Node
{
    string val;
    int lc;
    int rc;
}node[22];
int father[22];
int root;
void inorder(int r)
{
    bool flag = node[r].lc>0||node[r].rc>0;
    if(flag&&r!=root)
        printf("(");
    if(node[r].lc>0)
        inorder(node[r].lc);
    cout<<node[r].val;
    if(node[r].rc>0)
        inorder(node[r].rc);
    if(flag&&r!=root)
        printf(")");
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        father[i] = i;
    for(int i=1;i<=N;i++)
    {
        cin>>node[i].val>>node[i].lc>>node[i].rc;
        father[node[i].lc] = i;
        father[node[i].rc] = i;
    }
    root = 1;
    while(father[root]!=root)
    {
        root = father[root];
    }
    inorder(root);
    printf("\n");
    getchar();
    getchar();
    return 0;
}