class Solution {
public:
    bool judge(int x, int y, int u ,int v, vector<vector<int>>& good, vector<bool>& unhappy)
    {
        if(unhappy[x])
            return false;
        if(good[x][u]<good[x][y]&&good[u][x]<good[u][v])
        {
            if(!unhappy[x])
            {
                unhappy[x] = true;
                return true;
            }
        }
        return false;
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans = 0;
        int N = pairs.size();
        vector<vector<int>> good(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                int person = preferences[i][j];
                good[i][person] = j;
            }
        }
        vector<bool> unhappy(n);
        for(int i = 0;i<N;i++)
        {
            int x = pairs[i][0];
            int y = pairs[i][1];
            for(int j = i+1;j < N;j++)
            {
                int u = pairs[j][0];
                int v = pairs[j][1];
                if(judge(x,y,u,v,good,unhappy))
                    ans++;
                if(judge(x,y,v,u,good,unhappy))
                    ans++;
                
                if(judge(y,x,u,v,good,unhappy))
                    ans++;
                if(judge(y,x,v,u,good,unhappy))
                    ans++;
                
                if(judge(u,v,x,y,good,unhappy))
                    ans++;
                if(judge(u,v,y,x,good,unhappy))
                    ans++;
                
                if(judge(v,u,x,y,good,unhappy))
                    ans++;
                if(judge(v,u,y,x,good,unhappy))
                    ans++;
            }
        }
        return ans;
    }
};
