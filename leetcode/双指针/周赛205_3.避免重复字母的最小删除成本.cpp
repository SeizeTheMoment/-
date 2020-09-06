class Solution {
    public:
     int minCost(string s, vector<int> cost) {
        int n = cost.size();
        if (n == 1){
            return 0;
        }
        int i = 0;
        int j = 1;
        int res = 0;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                if(cost[i]<=cost[j])
                {
                    //删除i
                    res += cost[i];
                    i = j;
                    j++;
                }
                else{
                    //删除j
                    res += cost[j];
                    j++;
                }
            }
            else{
                i = j;
                j++;
            }
        }
        return res;
    }
};
