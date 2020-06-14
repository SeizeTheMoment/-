class TreeAncestor {
private:
    vector<vector<int>> f;
    vector<vector<int>> children;
public:
    TreeAncestor(int n, vector<int>& parent) {
        f = vector<vector<int>>(n,vector<int>(16,-1));
        children.resize(n);
        int root = 0;
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==-1)
            {
                root = i;
                continue;
            }
            children[parent[i]].push_back(i);
        }
        queue<int> que;
        que.push(root);
        while(que.size())
        {
            int ne = que.front();
            que.pop();
            for(int child : children[ne])
            {
                f[child][0] = parent[child];
                for(int k=1;k<16;k++)
                {
                    if(f[child][k-1]<0)
                        break;
                    f[child][k] = f[f[child][k-1]][k-1];
                }
                que.push(child);   
            }
            
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<16;i++)
        {
            if(k>>i&1)
            {
                node = f[node][i];
                if(node==-1)
                    return node;
            }
        }
         return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
