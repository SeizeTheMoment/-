#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 2010
using namespace std;
int N;
int pos=0;
int ar[MAX];
int node[MAX];
bool cmp(int a, int b)
{
    if(node[a]<node[b])
        return true;
    return false;
}
void build(int root)
{
    if(root>N)
        return;
    int lc = 2*root;
    int rc = 2*root+1;
    build(2*root);
    node[root]=ar[pos++];
    build(2*root+1);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&ar[i]);
    sort(ar,ar+N);
    build(1);
    for(int i=1;i<=N;i++)
    {
        if(i!=1)
            printf(" ");
        cout<<node[i];
    }

}
