#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 25

using namespace std;
 struct Node
 {
     int lc;
     int rc;
 }node[MAX];
int N;
bool is_root[MAX];
int maxi = -1;
int ans = 0;
void dfs(int r, int index)
{
    if(index>maxi)
    {
        ans = r;
        maxi = index;
    }
    //cout<<r<<" "<<node[r].lc<<" "<<node[r].rc<<endl;
    if(node[r].lc>=0)
        dfs(node[r].lc, 2*index+1);
    if(node[r].rc>=0)
        dfs(node[r].rc, 2*index+2);
}
int main()
{
    scanf("%d",&N);
    fill(is_root,is_root+N,true);
    for(int i=0;i<N;i++)
    {
        string a,b;
        cin>>a>>b;
        if(a=="-")
        {
            node[i].lc = -1;

        }
        else{
            node[i].lc = stoi(a);
            is_root[node[i].lc] = false;
        }
        if(b=="-")
        {
            node[i].rc = -1;

        }
        else{
            node[i].rc = stoi(b);
            is_root[node[i].rc] = false;

        }
    }
    int root = 0;
    for(int i=0;i<N;i++)
    {
        if(is_root[i])
        {
            root = i;
            break;
        }
    }
    dfs(root,0);
    //cout<<maxi<<endl;
    if(maxi==N-1)
    {
        printf("YES %d\n",ans);
    }
    else{
        printf("NO %d\n",root);
    }
    return 0;
}
