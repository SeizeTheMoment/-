class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int> > con_ind;
        con_ind.resize(n);
         for (int i = 0; i < connections.size(); i++) {
            con_ind[connections[i][0]].push_back(i);
            con_ind[connections[i][1]].push_back(i);
        }
        queue<int> que;
        vector<bool> vis;
        vis.resize(connections.size());
        int ans = 0;
        que.push(0);
        while(que.size())
        {
            int q = que.front();
            que.pop();
            for (auto ind : con_ind[q]) {
                if (vis[ind]) 
                    continue;
                vis[ind] = true;
                int s = connections[ind][0];
                int e = connections[ind][1];
                if(s==q)
                {
                    ans+=1;
                    s = e;
                }
                que.push(s);
            }
        }
        return ans;
    }
};
