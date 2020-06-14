
struct Node
{
    int val;
    int cnt;
    bool operator < (Node b)
    {
        return cnt < b.cnt;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<Node> node;
        unordered_map<int,int> pos;
        node.resize(arr.size());
        int t = 0;
        for(int x:arr)
        {
            if(pos.find(x)==pos.end())
            {
                pos[x] = t++;
                node[pos[x]].val = x;
                node[pos[x]].cnt = 1;
            }
            else{
                int p = pos[x];
                node[p].cnt++;
            }
        }
        int ind = 0;
        int N = t;
        int dec = 0;
        sort(node.begin(),node.begin()+t);
        while(ind<t&&k>0)
        {
            if(node[ind].cnt<=k)
            {
                k-=node[ind].cnt;
                dec++;
            }
            else{
                k = 0;
            }
            ind++;
        }
        return N-dec;
    }
};
