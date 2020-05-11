#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
map<int,vector<int>> graph;
map<int, bool> isboy;
map<pair<int,int>,bool> hascrush;
struct Node
{
    int x;
    int y;
    bool operator < (Node b)
    {
        if(x==b.x)
            return y<b.y;
        return x<b.x;
    }
};
int main()
{
    scanf("%d%d",&N,&M);
    while (M--)
    {
        string x,y;
        cin>>x>>y;
        int xx = stoi(x);
        int yy = stoi(y);
        xx = abs(xx);
        yy = abs(yy);
        if(x.length()==y.length())                 //同性别好朋友
        {    
            graph[xx].push_back(yy);
            graph[yy].push_back(xx);
        }
        hascrush[make_pair(xx,yy)] = true;
        hascrush[make_pair(yy,xx)] = true;
    }   
    int K;
    scanf("%d",&K);
    while(K--)
    {
        string x,y;
        cin>>x>>y;
        int xx = abs(stoi(x));
        int yy = abs(stoi(y));
        vector<Node> ans;
        for(int i=0;i<graph[xx].size();i++)
        {
            int idx = graph[xx][i];                   //第一个人的同性朋友
            for(int j=0;j<graph[yy].size();j++)
            {
                int idy = graph[yy][j];               //第二个人的同性朋友
                if(idx==yy||idy==xx)                  //排除掉第一个人的同性别朋友和第二个人是同一人
                    continue;
                if(hascrush[make_pair(idx,idy)])
                {
                    ans.push_back(Node{idx,idy});
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%04d %04d\n",ans[i].x,ans[i].y);
        }
    }
    return 0;
}