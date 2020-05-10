class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int N = hasApple.size();
        vector<int> father;
        vector<bool> visited;
        father.resize(N);
        visited.resize(N);
        father[0] = -1;
        for(auto edge:edges)
        {
            father[edge[1]] = edge[0];
        }
        int ans = 0;
        for(int i=1;i<N;i++)
        {
            if(hasApple[i]&&!visited[i])
            {
                int tmp = i;
                visited[tmp] = true;
                ans++;
                while(father[tmp]!=0&&!visited[father[tmp]])
                {
                    tmp = father[tmp];
                    visited[tmp] = true;
                    ans++;
                }
            }
        }
        return ans*2;
    }
};
