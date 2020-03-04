#include <string>
#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 800
int N;
int pre[MAX];
int in[MAX];
int post[MAX];
int node[MAX];
stack<int> s;
int pos = 0;
void rebuild(int L, int R, int n)
{
    if(L>=R)
    {
        node[n] = -1;
        return;
    }
    int root = pre[pos++];
    node[n] = root;
    int m = find(in, in+R,root) - in;
    rebuild(L,m,2*n);
    rebuild(m+1,R,2*n+1);
}
int k2 = 0;
void pushit(int n)
{
    if(node[n]<0)
        return;
    pushit(2*n);
    pushit(2*n+1);
    post[k2++] = node[n];
}
int main()
{
    scanf("%d",&N);
    int k0 = 0;
    int k1 = 0;
    for(int i=1;i<=2*N;i++)
    {
        string op;
        cin>>op;
        if(op=="Push\0"){
            int val;
            cin>>val;
            s.push(val);
            pre[k0++] = val;
        }
        else{
            in[k1++] = s.top();
            s.pop();
        }
    }
    rebuild(0,N,1);
    pushit(1);
    for(int i=0;i<N;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",post[i]);
    }
    return 0;
}
