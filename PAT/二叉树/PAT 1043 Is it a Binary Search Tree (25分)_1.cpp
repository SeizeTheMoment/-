#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> pre,in,post;
bool is_mirror = false;
void getPost(int root,int iL, int iR)
{
    if(iL>iR)
        return;
    int pos = iR+1;
    if(!is_mirror)
    {
        for(int i=iL;i<=iR;i++)
        {
            if(pre[root]==in[i])
            {
                pos = i;
                break;
            }
        }
    }
    else{
        for(int i=iL;i<=iR;i++)
        {
            if(pre[root]==in[i])
                pos = i;
        }
    }
    getPost(root+1,iL,pos-1);
    getPost(root+pos-iL+1,pos+1,iR);
    post.push_back(pre[root]);
}
int main()
{
    scanf("%d",&N);
    pre.resize(N);
    in.resize(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&pre[i]);
        in[i] = pre[i];
    }
    sort(in.begin(),in.end());
    getPost(0,0,N-1);
    if(post.size()==N)
    {
        printf("YES\n");
    }
    else{
        is_mirror = true;
        post.clear();
        reverse(in.begin(),in.end());
        getPost(0,0,N-1);
        if(post.size()==N)
            printf("YES\n");
        else{
            printf("NO\n");
            return 0;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",post[i]);
    }
    return 0;
}

