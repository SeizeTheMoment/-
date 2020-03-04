#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#define MAX 1010
using namespace std;
int N;
int pre[MAX];
vector<int> post;
bool is_mirror = false;
void rebuild(int L, int R)
{
    if(L>R)
        return;
    int i = L+1;
    int j = R;
    if(!is_mirror)
    {
        while(i<=R&&pre[L]>pre[i]) i++;
        while(j>L&&pre[L]<=pre[j]) j--;
    }
    else{
        while(i<=R&&pre[L]<=pre[i]) i++;
        while(j>L&&pre[L]>pre[j]) j--;
    }
    if(i-j!=1)
        return;
    rebuild(L+1,j);
    rebuild(i,R);
    post.push_back(pre[L]);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&pre[i]);
    rebuild(0,N-1);
    if(post.size()==N)
        cout<<"YES"<<endl;
    else{
        post.clear();
        is_mirror = true;
        rebuild(0,N-1);
        if(post.size()==N)
            cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
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

